package Principal;

import java.util.*;

public class Principal {

    public static void main(String[] args) throws Exception {
        ArrayList<Airport> airportsList = new ArrayList<Airport>();
        airportsList = ReadCSV.getAirportsData();

        Menu mainMenu = new Menu(airportsList);

        mainMenu.showMenu();

    }
}
