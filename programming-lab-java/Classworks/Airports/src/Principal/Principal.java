package Principal;

import Dijkstra.*;
import java.util.*;

public class Principal {

    public static void main(String[] args) throws Exception {
        ArrayList<Airport> airportsList = new ArrayList<Airport>();
        airportsList = ReadCSV.getAirportsData();
        Graph airportsGraph = new Graph(airportsList);
        Airport originAp = airportsList.get(0);
        Airport destinyAp = airportsList.get(10);
        Node destinyNode = DijkstraAlgorithm.calculateShortestPathFromSource(airportsGraph, originAp, destinyAp);
        System.out.printf("\nTrecho %s -> %s\n", originAp.getCode(), destinyAp.getCode());
        System.out.println("---------------------");
        System.out.print("| ");

        for(Node apNode: destinyNode.getShortestPath()) {
            System.out.print(apNode.getAirport().getCode());
            System.out.print(" -> ");
        }
        System.out.println(destinyAp.code);
        System.out.printf("| d = %.2f Km\n",destinyNode.getDistance());

        Node middleNode = airportsGraph.getNodeByCode("RBR");
        Double d1 = originAp.getDirectDistanceBetween(middleNode.getAirport());
        Double d2 = middleNode.getAirport().getDirectDistanceBetween(destinyAp);

        System.out.printf("\n%.2f + %.2f = %.2f\n", d1, d2, d1+d2);
    }
}
