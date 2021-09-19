import java.io.IOException;

/**
 * Lab2 is a Java class containing a main method to run your program when completed.
 * This class will not compile until you have completed the requirements outlined in 
 * the lab description.
 * 
 * @author Amanda Fernandez (abc123)
 * UTSA CS 3443 - Lab 2
 * Fall 2021
 */
public class Lab2 {

	public static void main( String[] args ) {
		
		try {
			
			Team cap = new Team( "A" );
			cap.loadAvengers( "data-A.csv" );
			System.out.println( cap );
			
			Team stark = new Team( "B" );
			stark.loadAvengers( "data-B.csv" );
			System.out.println( stark );
			
		}catch( IOException e ) {
			System.out.println( "Error loading the file - please check its location." );
			e.printStackTrace();
		}
	}	
}