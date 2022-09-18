package Dijkstra;

import java.util.*;


public class DijkstraAlgorithm {

    public static Node calculateShortestPathFromSource(Graph graph, String originApCode, String destinyApCode) {

        Node originNode = graph.getNodeByCode(originApCode);
        Node destinyNode = graph.getNodeByCode(destinyApCode);

        originNode.setDistance(0.0);
        HashSet<Node> settledNodes = new HashSet<Node>();
        HashSet<Node> unsettledNodes = new HashSet<Node>();
        graph.filterSourceNode(originNode, destinyNode);

        unsettledNodes.add(originNode);

        while (unsettledNodes.size() != 0) {
            Node currentNode = getLowestDistanceNode(unsettledNodes);
            unsettledNodes.remove(currentNode);
            for (Map.Entry< Node, Double> adjacencyPair:
                    currentNode.getAdjacentNodes().entrySet()) {
                Node adjacentNode = adjacencyPair.getKey();
                Double distanceBetween = adjacencyPair.getValue();
                if (!settledNodes.contains(adjacentNode)) {
                    calculateMinimumDistance(adjacentNode, distanceBetween, currentNode);
                    unsettledNodes.add(adjacentNode);
                }
            }
            settledNodes.add(currentNode);
        }
        return destinyNode;
    }

    private static Node getLowestDistanceNode(HashSet < Node > unsettledNodes) {
        Node lowestDistanceNode = null;
        Double lowestDistance = Double.MAX_VALUE;
        for (Node node: unsettledNodes) {
            Double nodeDistance = node.getDistance();
            if (nodeDistance < lowestDistance) {
                lowestDistance = nodeDistance;
                lowestDistanceNode = node;
            }
        }
        return lowestDistanceNode;
    }

    private static void calculateMinimumDistance(Node evaluationNode, Double distanceBetween, Node sourceNode) {
        Double sourceDistance = sourceNode.getDistance();
        if (sourceDistance + distanceBetween < evaluationNode.getDistance()) {
            evaluationNode.setDistance(sourceDistance + distanceBetween);
            LinkedList<Node> shortestPath = new LinkedList<>(sourceNode.getShortestPath());
            shortestPath.add(sourceNode);
            evaluationNode.setShortestPath(shortestPath);
        }
    }
}

