package Principal;

import java.util.*;
import Dijkstra.*;

public class Menu {

// ATTRIBUTES
  Graph airportsGraph;
  String originCode, destinyCode;
  HashSet<String> statesList;
  HashSet<String> citiesList;


// METHODS
  // Constructor
  public Menu(ArrayList<Airport> airportsList) {
    airportsGraph = new Graph(airportsList);
    statesList = new HashSet<>();
    citiesList = new HashSet<>();
  }
  
  public void showMenu() {        
    System.out.println("--------- ROTAS ÁREAS ---------\n");
    selectDestiny();
    selectOrigin();
    printShortestPath();
    }
    
    
    private void selectDestiny() {
    Scanner obj = new Scanner(System.in);
    
    System.out.println("Seleção do Destino:");
    System.out.println("1. Inserir código do Aeroporto de destino");
    System.out.println("2. Listar códigos dos Aeroportos");
    System.out.print("Escolha uma opção: ");

    try {
      Integer option = obj.nextInt();
      switch(option) {
        case 1:
          destinyCode = insertApCode();
          if(destinyCode == null)
            selectDestiny();
          break;
        case 2:
          listApCodes();
          selectDestiny();
          break;
        default:
          System.out.println("\nOpção inválida!\n");
          showMenu();
      }
    }
    catch(Exception e) {
      System.out.println("Opção inválida!\n");
      selectDestiny();
    }
    
  }
  
  
  private void selectOrigin() {
    Scanner obj = new Scanner(System.in);
    
    System.out.println("Seleção da Origem:");
    System.out.println("1. Inserir código do Aeroporto de origem");
    System.out.println("2. Listar códigos dos Aeroportos");
    System.out.print("Escolha uma opção: ");

    try {
      Integer option = obj.nextInt();
      switch(option) {
        case 1:
          originCode = insertApCode();
          if(originCode == null)
            selectOrigin();
          break;
        case 2:
          listApCodes();
          selectOrigin();
          break;
        default:
          System.out.println("\nOpção inválida!\n");
          showMenu();
      }
    }
    catch(Exception e) {
      System.out.println("Opção inválida!\n");
      selectOrigin();
    }
  }
  
  private void printShortestPath() {
    Node destinyNode = DijkstraAlgorithm.calculateShortestPathFromSource(airportsGraph, originCode, destinyCode);
        
        System.out.printf("\nTrecho %s -> %s\n", originCode, destinyCode);
        System.out.println("---------------------");
        System.out.print("| ");

        for(Node apNode: destinyNode.getShortestPath()) {
            System.out.print(apNode.getAirport().getCode());
            System.out.print(" -> ");
        }
        System.out.println(destinyCode);
        System.out.printf("| %.2f Km\n",destinyNode.getDistance());
  }

  private String insertApCode() {
    Scanner obj = new Scanner(System.in);
    
    System.out.print("Insira o código do Aeroporto: ");
    try {
      String apCode = obj.nextLine();
      if(apCode.length() != 3) {
        System.out.println("O código deve ser composto por 3 letras maiúsculas!");
        return null;
      }
      if(!verifyCode(apCode)) {
        System.out.println("\nNão existe aeroporto internacional brasileiro com esse código!\n");
        return null;
      }
      System.out.println();
      return apCode;
    }
    catch(Exception e) {
      System.out.println("Código inválido!\n");
      return null;
    }
  }

  private boolean verifyCode(String apCode) {
    for(Node apNode: airportsGraph.getAirPortNodes()) {
      if(apCode.equals(apNode.getAirport().getCode()))
        return true;
    }
    return false;
  }

  private void listApCodes() {
    Scanner sc = new Scanner(System.in);
    System.out.println("\n------ ESTADOS ------");
    for(Node apNode: airportsGraph.getAirPortNodes()) {
      String apState = apNode.getAirport().getState();
      if(!statesList.contains(apState))
        statesList.add(apState);
        System.out.println(apState);
    }
    System.out.print("\nEscolha um dos estados acima: ");
    
    try {
      String stateSelected = sc.nextLine();
      if(!verifyState(stateSelected))
        listApCodes();
  
      System.out.println("\n------ MUNICÍPIOS ------");
      for(Node apNode: airportsGraph.getAirPortNodes()) {
        String apCity = apNode.getAirport().getCity();
        if(!citiesList.contains(apCity) && stateSelected.equals(apNode.getAirport().getState())) {
          citiesList.add(apCity);
          System.out.println(apCity);
        }
      }
      System.out.print("\nEscolha um dos estados acima: ");

      try {
        String citySelected = sc.nextLine();
        if(!verifyCity(citySelected))
          listApCodes();
        
        System.out.println("\n------ AEROPORTOS ------");
        for(Node apNode: airportsGraph.getAirPortNodes()) {
          if(citySelected.equals(apNode.getAirport().getCity())) {
            System.out.println(apNode.getAirport().getCode() + "\n");
          }
        }
      }
      catch(Exception e) {
        System.out.println("Município inválido!\n");
        listApCodes();
      }
    }
    catch(Exception e) {
      System.out.println("Estado inválido!\n");
      listApCodes();
    }
      
  }

  private boolean verifyState(String apState) {
    if(!statesList.contains(apState)) {
      System.out.println("Estado inválido!\n");
      return false;
    }
    return true;
  }

  private boolean verifyCity(String apCity) {
    if(!citiesList.contains(apCity)) {
      System.out.println("Município inválido!\n");
      return false;
    }
    return true;
  }
  
}
