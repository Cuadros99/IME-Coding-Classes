package Dijkstra;

import Principal.Airport;
import java.util.*;


public class DijkstraAlgorithm {

    public static Node calculateShortestPathFromSource(Graph graph, Airport originAp, Airport destinyAp) {

        graph.getNodeByCode(originAp.getCode()).setDistance(0.0);
        HashSet<Node> settledNodes = new HashSet<Node>();
        HashSet<Node> unsettledNodes = new HashSet<Node>();
        graph.filterSourceNode(graph.getNodeByCode(originAp.getCode()), graph.getNodeByCode(destinyAp.getCode()));

        unsettledNodes.add(graph.getNodeByCode(originAp.getCode()));

        while (unsettledNodes.size() != 0) {
            Node currentNode = getLowestDistanceNode(unsettledNodes);
            unsettledNodes.remove(currentNode);
            for (Map.Entry< Node, Double> adjacencyPair:
                    currentNode.getAdjacentNodes().entrySet()) {
                Node adjacentNode = adjacencyPair.getKey();
                Double edgeWeight = adjacencyPair.getValue();
                if (!settledNodes.contains(adjacentNode)) {
                    calculateMinimumDistance(adjacentNode, edgeWeight, currentNode);
                    unsettledNodes.add(adjacentNode);
                }
            }
            settledNodes.add(currentNode);
        }
        return graph.getNodeByCode(destinyAp.getCode());
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

    private static void calculateMinimumDistance(Node evaluationNode,
                                                 Double edgeWeigh, Node sourceNode) {
        Double sourceDistance = sourceNode.getDistance();
        if (sourceDistance + edgeWeigh < evaluationNode.getDistance()) {
            evaluationNode.setDistance(sourceDistance + edgeWeigh);
            LinkedList<Node> shortestPath = new LinkedList<>(sourceNode.getShortestPath());
            shortestPath.add(sourceNode);
            evaluationNode.setShortestPath(shortestPath);
        }
    }
}

