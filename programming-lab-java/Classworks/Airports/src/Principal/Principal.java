package Principal;

import Dijkstra.*;
import java.util.*;

public class Principal {

    public static void main(String[] args) throws Exception {
        ArrayList<Airport> airportsList = new ArrayList<Airport>();
        airportsList = ReadCSV.getAirportsData();
        Graph airportsGraph = new Graph(airportsList);
        Node destinyNode = DijkstraAlgorithm.calculateShortestPathFromSource(airportsGraph, airportsList.get(0), airportsList.get(10));
        System.out.printf("d = %f Km\n",destinyNode.getDistance());
        /*int i=0;
        Airport originAp = airportsList.get(i);
        Airport destinyAp = airportsList.get(i+1);
        System.out.printf("%s -> %s: %.2f Km \n", originAp.getCode(), destinyAp.getCode(), originAp.getDistanceBetween(destinyAp) );
        */
    }
}
