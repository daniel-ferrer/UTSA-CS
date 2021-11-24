/**
 * 
 */
package application.model;

import java.util.ArrayList;
import java.util.Random;

import application.controller.MainController;
import javafx.concurrent.Task;
import javafx.scene.layout.Pane;


/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class AvengerTask implements Runnable {
	// class attributes
	ArrayList<Avenger> avengers;
	Pane earthPane;

	// default constructor
	public AvengerTask() { }
	
	
	// constructor given @param values
	public AvengerTask(ArrayList<Avenger> avengers, Pane earthPane) {
		this.avengers = avengers;
		this.earthPane = earthPane;
	}


	@Override
	public void run() {
		MainController controller = new MainController();
		Random rand = new Random();
		for(Avenger avenger: avengers) {
			
			if(rand.nextInt(5) == 0) { // 10% chance to change loc
				
				double maxLat = earthPane.getPrefHeight();
				double maxLong = earthPane.getPrefWidth();
				double new_lat = -1 + (maxLat - (-1)) * rand.nextDouble();
				double new_long = -1 + (maxLong - (-1)) * rand.nextDouble();
								
				avenger.set_lat(String.valueOf(new_lat));
				avenger.set_long(String.valueOf(new_long));
				
				System.out.printf("In thread, %s's img string is %s\n", avenger.getAlias(), avenger.getImg());
				System.out.printf("In thread, %s's color code is %s\n", avenger.getAlias(), avenger.getColorCode());
				
				controller = new MainController();
				controller.addAvengerLocation(avenger, true, earthPane);
				
			}
		}
		//controller.updateTime();
	}

	
}





//public void runThreadedTask() {
//	System.out.println("Running long task...with a thread!");
//	try {
//		
//		Thread th = new Thread( new Task(){                // put the task in its own thread
//			@Override
//			protected String call() throws Exception {
//						
//				String status = "";
//				for(int i = 1; i <= 10; i++) {
//					status = "Processing " + i + " of " + 10;
//					final String fstat = status;
//					
//					// update the label on the JavaFx Application Thread!
//					Platform.runLater(new Runnable() {
//			            @Override
//			            public void run() {
//			            		setStatus(fstat);
//			            }
//			        });
//					Thread.sleep(1000);
//				}
//				return status;
//			}
//		});													
//		
//		// init and run the new thread
//		th.setDaemon(true);									
//		th.start();
//		Thread.sleep(1000);
//	}catch (InterruptedException e) {
//		e.printStackTrace();
//	}
//}
