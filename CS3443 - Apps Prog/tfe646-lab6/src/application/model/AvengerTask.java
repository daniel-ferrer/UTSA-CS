/**
 * 
 */
package application.model;

import java.util.ArrayList;


/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class AvengerTask extends Thread {
	// class attributes
	ArrayList<Avenger> avengers;

	// default constructor
	public AvengerTask() { }
	
	
	// constructor given @param values
	public AvengerTask(ArrayList<Avenger> avengers) {
		this.avengers = avengers;
		
		
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
