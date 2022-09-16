package Dijkstra;

import Principal.Airport;

import java.util.*;

public class Graph {
    private HashSet<Node> airPortNodes = new HashSet<>();

    private void addNode(Node nodeA) {
        airPortNodes.add(nodeA);
    }
    public Graph(ArrayList<Airport> airportsList) {
        for(int i=0; i < airportsList.size(); i++) {
            Node aux = new Node(airportsList.get(i));
            Airport originAp = aux.getAirport();
            for(int j=0; j < airportsList.size(); j++) {
                if(i!=j) {
                    Node destinyApNode = new Node(airportsList.get(j));
                    Double distance = originAp.getDistanceBetween(destinyApNode.getAirport());
                    aux.addAdjacentNodes(destinyApNode, distance);
                }
            }
            addNode(aux);
        }
    }
    public Node getNode(Node requestedNode) {
        for(Node apNode: airPortNodes) {
            if(apNode.getAirport().getCode() == requestedNode.getAirport().getCode())
                return apNode;
        }
        return null;
    }

    public Node getNodeByCode(String code) {
        for(Node apNode: airPortNodes) {
            if(apNode.getAirport().getCode() == code)
                return apNode;
        }
        return null;
    }

    public void filterSourceNode(Node sourceNode, Node destinyNode) {
        for(Node apNode: airPortNodes) {
            if(apNode.getAirport().getCode() == sourceNode.getAirport().getCode())
                apNode.removeAdjacentNode(destinyNode);
        }
    }
}
