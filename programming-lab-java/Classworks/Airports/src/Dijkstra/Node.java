package Dijkstra;

import Principal.Airport;
import java.util.*;


public class Node {

    private Airport ap;
    private LinkedList<Node> shortestPath = new LinkedList<>();
    private Double distance = Double.MAX_VALUE;
    HashMap<Node, Double> adjacentNodes = new HashMap<>();

    public Node(Airport ap) {
        this.ap = ap;
    }
    public void addAdjacentNodes(Node destination, Double distance) {
        adjacentNodes.put(destination, distance);
    }
    public Airport getAirport() {
        return ap;
    }
    public LinkedList<Node> getShortestPath() {
        return shortestPath;
    }

    public Double getDistance() {
        return distance;
    }
    public HashMap<Node, Double> getAdjacentNodes() {
        return adjacentNodes;
    }
    public void setShortestPath(LinkedList<Node> shortestPath) {
        this.shortestPath = shortestPath;
    }
    public void setDistance(Double distance) {
        this.distance = distance;
    }
    public void removeAdjacentNode(Node airportNode) {
        this.adjacentNodes.remove(airportNode);
    }
}