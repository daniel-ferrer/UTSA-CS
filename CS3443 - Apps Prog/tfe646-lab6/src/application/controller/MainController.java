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
	ArrayList<Avenger> globalAvengers;

	
	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		globalAvengers = new ArrayList<Avenger>();
		
		resetView();

		try { loadAvengers(dataFP); } 
		catch (FileNotFoundException e) { 
			e.printStackTrace(); 
		}		
		
	}
	
	// Will set all JavaFX objects to initial view values
	public void resetView() {
		avengerImg.setCache(false);
		avengerImg.setImage(null);
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
				
				addAvengerLocation(avenger);
				globalAvengers.add(avenger);
			}
			
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	// Add marker to display Avenger's initial location
	public void addAvengerLocation(Avenger avenger) {
		
		// Defining an event handler to display avenger's info when marker is clicked
		EventHandler<InputEvent> handler = new EventHandler<InputEvent>() {
			public void handle(InputEvent event) {
				displaySelectedAvenger(avenger);
			}
		};
		
		switch(avenger.getAlias()) {
			case "Captain America":
				Circle cptPoint = new Circle();
				cptPoint.setFill(cptColor.getFill());
				cptPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				cptPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				cptPoint.setRadius(7);
				earthPane.getChildren().add(cptPoint);
				cptPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "Hulk":
				Circle hulkPoint = new Circle();
				hulkPoint.setFill(hulkColor.getFill());
				hulkPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				hulkPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				hulkPoint.setRadius(7);
				earthPane.getChildren().add(hulkPoint);
				hulkPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "God Of Thunder":
				Circle thorPoint = new Circle();
				thorPoint.setFill(thorColor.getFill());
				thorPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				thorPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				thorPoint.setRadius(7);
				earthPane.getChildren().add(thorPoint);
				thorPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "Black Widow":
				Circle widowPoint = new Circle();
				widowPoint.setFill(widowColor.getFill());
				widowPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				widowPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				widowPoint.setRadius(7);
				earthPane.getChildren().add(widowPoint);
				widowPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "Doctor Strange":
				Circle doctorPoint = new Circle();
				doctorPoint.setFill(doctorColor.getFill());
				doctorPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				doctorPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				doctorPoint.setRadius(7);
				earthPane.getChildren().add(doctorPoint);
				doctorPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "Iron Man":
				Circle ironmanPoint = new Circle();
				ironmanPoint.setFill(ironmanColor.getFill());
				ironmanPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				ironmanPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				ironmanPoint.setRadius(7);
				earthPane.getChildren().add(ironmanPoint);
				ironmanPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "Black Panther":
				Circle pantherPoint = new Circle();
				pantherPoint.setFill(pantherColor.getFill());
				pantherPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				pantherPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				pantherPoint.setRadius(7);
				earthPane.getChildren().add(pantherPoint);
				pantherPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "Hawkeye":
				Circle hawkeyePoint = new Circle();
				hawkeyePoint.setFill(hawkeyeColor.getFill());
				hawkeyePoint.setCenterX(Double.parseDouble(avenger.get_long()));
				hawkeyePoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				hawkeyePoint.setRadius(7);
				earthPane.getChildren().add(hawkeyePoint);
				hawkeyePoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "Spiderman":
				Circle spidermanPoint = new Circle();
				spidermanPoint.setFill(spidermanColor.getFill());
				spidermanPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				spidermanPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				spidermanPoint.setRadius(7);
				earthPane.getChildren().add(spidermanPoint);
				spidermanPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;
				
			case "Captain Marvel":
				Circle marvelPoint = new Circle();
				marvelPoint.setFill(marvelColor.getFill());
				marvelPoint.setCenterX(Double.parseDouble(avenger.get_long()));
				marvelPoint.setCenterY(Double.parseDouble(avenger.get_lat()));
				marvelPoint.setRadius(7);
				earthPane.getChildren().add(marvelPoint);
				marvelPoint.addEventHandler(MouseEvent.MOUSE_CLICKED, handler);

				break;				
		}	
		
	}
	
	// Display selected Avenger's image and information
	public void displaySelectedAvenger(Avenger avenger) {
		// define path to avenger's image
		String imgPath = "data/" + avenger.getAlias().toLowerCase().replace(" ", "_") + ".jpg";
		String info = "";
		
		// display selected avenger's image and 
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

}
