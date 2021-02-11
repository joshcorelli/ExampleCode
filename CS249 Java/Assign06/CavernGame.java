package edu.corellj.Assign06;
//NOTE: CHANGE realemj to YOUR SITNETID!!!
import edu.corellj.Assign05.*;

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class CavernGame {

    public static void main(String [] args) {
    	// Create map
    	CharImage baseMap = new CharImage(12, 30, '.');
    	// Create list of Creatures
		ArrayList<Creature> allCreatures = new ArrayList<>();
    	// Create inventory
		ArrayList<Item> inventory = new ArrayList<>();
		// Have list of Drawable things
		ArrayList<Drawable> drawList = new ArrayList<>();

		try {
			// Ask user for level name
		    Scanner inputUser = new Scanner(System.in);
		    System.out.println("Enter level filename:");
		    String levelName = inputUser.nextLine();

		    // Open level file
			Scanner levelFile = new Scanner(new File(levelName));

			// Read in the number of lines in the file
		    int numLines = levelFile.nextInt();

		    // For each line...
		    for(int i = 0; i < numLines; i++) {
				String typeObject = levelFile.next();
				
				Loadable m = null;
				
				switch(typeObject) {
				    case "Troll":
				    	m = new Troll();
				    	break;
				    case "Rat":
				    	m = new Rat();
				    	break;
					case "Item":
						m = new Item();
						break;
					case "Book":
						m = new Book();
						break;
				    default:
				    	throw new GameFileException("Unknown type: " + typeObject);
				}
				
				if(m != null) {
				    m.load(levelFile);

				    if(m instanceof Creature) {
				    	allCreatures.add((Creature)m);
					}

				    if(m instanceof Item) {
				    	inventory.add((Item)m);
					}

				    if(m instanceof Drawable) {
				    	drawList.add((Drawable)m);
					}
				}	
		    }
		}
		catch(Exception e) {
		    System.err.println("Game File Error: " + e.getMessage());
		    //e.printStackTrace();
		}

		// Draw on map
		for(int i = 0; i < drawList.size(); i++) {
			drawList.get(i).draw(baseMap);
		}

		// Print map
		System.out.println(baseMap);

		// Print list of Creatures
		System.out.println("CREATURES:");
		for(int i = 0; i < allCreatures.size(); i++) {
			System.out.println(allCreatures.get(i));
		}

		// Print inventory
		System.out.println("INVENTORY:");
		for(int i = 0; i < inventory.size(); i++) {
			System.out.println(inventory.get(i));
		}
	}
}
