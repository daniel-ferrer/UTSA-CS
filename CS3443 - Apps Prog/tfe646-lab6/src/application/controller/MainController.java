package application.controller;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.ResourceBundle;
import java.util.Timer;

import application.model.Avenger;
import application.model.AvengerTask;
import javafx.application.Platform;
import javafx.concurrent.Task;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.InputEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Circle;

public class MainController implements Initializable {
	@FXML
	private ImageView earth, avengerImg;
	@FXML
	private Circle cptColor, hulkColor, thorColor, widowColor, doctorColor;
	@FXML
	private Circle ironmanColor, pantherColor, spidermanColor, hawkeyeColor, marvelColor;
	@FXML
	private Label cptStatusLbl, hulkStatusLbl, thorStatusLbl, widowStatusLbl, doctorStatusLbl;
	@FXML
	private Label ironmanStatusLbl, pantherStatusLbl, hawkeyeStatusLbl, spidermanStatusLbl, marvelStatusLbl;
	@FXML
	private Label avengerDescLbl, lastUpdateLbl;
	@FXML
	private Pane earthPane;
	
	// Helper Vars
	private final String dataFP = "./data/data.csv";
	ArrayList<Avenger> globalAvengers = new ArrayList<Avenger>();

	
	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {

		
		resetView();

		try { loadAvengers(dataFP); } 
		catch (FileNotFoundException e) { 
			e.printStackTrace(); 
		}		
		
		AvengerTask task = new AvengerTask(globalAvengers, earthPane);
		Thread t = new Thread(task);
		t.setDaemon(true);
		t.start();
		
	}
	
	// Will set all JavaFX objects to initial view values
	public void resetView() {
		avengerDescLbl.setText(null);
		updateTime();
	}
	
	// Initialize all Avengers in data.csv
	public void loadAvengers(String dataFP) throws FileNotFoundException {
		String line = "";
		String delim = ",";
		
		try {
			BufferedReader reader = new BufferedReader(new FileReader(dataFP));
			while((line = reader.readLine()) != null) {
				
				String splitted[] = line.split(delim);			
				
				Avenger avenger = new Avenger(splitted[0].strip(), splitted[1], splitted[2], splitted[3], splitted[4],
											  splitted[5], splitted[6], splitted[7], splitted[8]);
				
				addAvengerLocation(avenger, false, earthPane);
				
			}
			
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	// Add marker to display Avenger's initial location
	public void addAvengerLocation(Avenger avenger, boolean flag, Pane earthPane) {
		
		// Defining an event handler to display avenger's info when marker is clicked
		EventHandler<InputEvent> handler = new EventHandler<InputEvent>() {
			public void handle(InputEvent event) {
				displaySelectedAvenger(avenger);
			}
		};
		
		
		System.out.printf("color code for %s is %s\n", avenger.getAlias(), avenger.getColorCode());
		
		switch(avenger.getAlias()) {
			case "Captain America":
				Circle cptPoint = new Circle();

				if(avenger.getColorCode() == null && !flag)
					cptPoint.setFill(cptColor.getFill());
				
				cptPoint.setFill(avenger.getColorCode());
				
				cptPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				cptPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				cptPoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(cptPoint);
				}
				cptPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(cptPoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "Hulk":
				Circle hulkPoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					hulkPoint.setFill(hulkColor.getFill());
				
				hulkPoint.setFill(avenger.getColorCode());
				
				hulkPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				hulkPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				hulkPoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(hulkPoint);
				}
				hulkPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(hulkPoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "God Of Thunder":
				Circle thorPoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					thorPoint.setFill(thorColor.getFill());
				
				thorPoint.setFill(avenger.getColorCode());
				
				thorPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				thorPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				thorPoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(thorPoint);
				}
				thorPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(thorPoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "Black Widow":
				Circle widowPoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					widowPoint.setFill(widowColor.getFill());
				
				widowPoint.setFill(avenger.getColorCode());
				widowPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				widowPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				widowPoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(widowPoint);
				}
				widowPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(widowPoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "Doctor Strange":
				Circle doctorPoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					avenger.setColorCode(doctorColor.getFill());
				
				doctorPoint.setFill(avenger.getColorCode());
				doctorPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				doctorPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				doctorPoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(doctorPoint);
				}
				doctorPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(doctorPoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "Iron Man":
				Circle ironmanPoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					avenger.setColorCode(ironmanColor.getFill());
				
				ironmanPoint.setFill(avenger.getColorCode());
				ironmanPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				ironmanPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				ironmanPoint.setRadius(7);
				globalAvengers.add(avenger);
				if(flag) {
					earthPane.getChildren().remove(ironmanPoint);
				}
				ironmanPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(ironmanPoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "Black Panther":
				Circle pantherPoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					avenger.setColorCode(pantherColor.getFill());
				
				pantherPoint.setFill(avenger.getColorCode());
				pantherPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				pantherPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				pantherPoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(pantherPoint);
				}
				pantherPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(pantherPoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "Hawkeye":
				Circle hawkeyePoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					avenger.setColorCode(hawkeyeColor.getFill());
				
				hawkeyePoint.setFill(avenger.getColorCode());
				hawkeyePoint.setCenterX(Double.parseDouble(avenger.get_long()));
				hawkeyePoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				hawkeyePoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(hawkeyePoint);
				}
				hawkeyePoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(hawkeyePoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "Spiderman":
				Circle spidermanPoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					avenger.setColorCode(spidermanColor.getFill());
				
				spidermanPoint.setFill(avenger.getColorCode());
				spidermanPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				spidermanPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				spidermanPoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(spidermanPoint);
				}
				spidermanPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(spidermanPoint);
				
				globalAvengers.add(avenger);
				break;
				
			case "Captain Marvel":
				Circle marvelPoint = new Circle();
				
				if(avenger.getColorCode() == null && !flag)
					avenger.setColorCode(marvelColor.getFill());
				
				marvelPoint.setFill(avenger.getColorCode());
				marvelPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				marvelPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				marvelPoint.setRadius(7);
				
				if(flag) {
					earthPane.getChildren().remove(marvelPoint);
				}
				marvelPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);
				earthPane.getChildren().add(marvelPoint);
				
				globalAvengers.add(avenger);
				break;				
		}
		
		if(flag)
			updatePane(earthPane);
		
	}
	
	// Display selected Avenger's image and information
	public void displaySelectedAvenger(Avenger avenger) {
		// define path to avenger's image
		String imgPath = "data/" + avenger.getAlias().toLowerCase().replace(" ", "_") + ".jpg";
		String info = "";
		
		avengerImg.setImage(new Image(avenger.getImg()));
		
		info += avenger.getName() + "\n";
		info += avenger.getAlias() + "\n";
		info += "Height: " + avenger.getHeightFt() + "'" + avenger.getHeightIn() + "\"\n";
		info += "Weight: " + avenger.getWeight() + "lbs";
		avengerDescLbl.setText(info);
	}
	
	// Update label with last location update time
	public void updateTime() {
		String formatter = new SimpleDateFormat("MMM dd, yyyy HH:mm:ss").format(new Date());
		lastUpdateLbl.setText("Last updated: " + formatter);
	}
	
	public void updatePane(Pane earthPane) {
		this.earthPane = earthPane;
	}

}
