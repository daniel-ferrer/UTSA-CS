package application.controller;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

import application.model.Role;
import application.model.User;
import javafx.event.ActionEvent;

import javafx.scene.control.Label;

import javafx.scene.control.TextArea;

import javafx.scene.image.ImageView;
import javafx.stage.Stage;

public class ActViewController implements Initializable {
	@FXML
	private ImageView hamiltonImg;
	@FXML
	private Label actNumLbl;
	@FXML
	private TextArea actTA;
	@FXML
	private Button logoutBtn;
	@FXML
	private Label displayUsernameLbl;
	@FXML
	private Button backBtn;
	@FXML
	private Label noScenesMsg;
	
	// Helper vars
	private int actNumber;
	private final String act1Path = "./data/act1.txt";
	private final String act2Path = "./data/act2.txt";
	private final String viewPath = "/main/resources/fxml/view/RoleView.fxml";
	private final String loginPath = "/main/resources/fxml/view/Login.fxml";
	
	User _usr; // global User obj will be used to populate labels in view
	
	@Override
	public void initialize(URL arg0, ResourceBundle arg1) { actNumLbl.setText("");	actTA.setText("");}

	// Event Listener on Button[#logoutBtn].onAction
	// Will send user back to Login.fxml
	@FXML
	public void logoutBtnClicked(ActionEvent event) {
		Node node = (Node) event.getSource();
		Stage stage = (Stage) node.getScene().getWindow();
		try {
			FXMLLoader loader = new FXMLLoader (getClass().getResource(loginPath));
			Parent root = (Parent) loader.load();
			LoginController controller = loader.getController();
			Scene scene = new Scene(root, 800, 800);
			stage.setScene(scene);
			stage.setTitle("Login");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	// Event Listener on Button[#backBtn].onAction
	// Will send user back to RoleView.fxml
	@FXML
	public void backBtnClicked(ActionEvent event) {
		Node node = (Node) event.getSource();
		Stage stage = (Stage) node.getScene().getWindow();
		try {
			FXMLLoader loader = new FXMLLoader (getClass().getResource(viewPath));
			Parent root = (Parent) loader.load();
			RoleViewController controller = loader.getController();
			controller.intakeUser(_usr);
			Scene scene = new Scene(root, 800, 800);
			stage.setScene(scene);
			stage.setTitle("Roles");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	// Method will populate ActView.fxml objects based on user
	public void intakeUser(User user) {
		_usr = user;
		displayUsernameLbl.setText(user.getUsername());
		if(user.getRoles() == null) { // display error msg if user has no roles
			noScenesMsg.setVisible(true);
		} else findUserActs(user.getRoles());
	}
	
	// Finds acts where user has a role and display
	public void findUserActs(ArrayList<Role> roles) {
		String role1 = "", role2 = "";
		
		for(Role role: roles) {
			String str = role.getName();
			String[] splitted = str.split(" ");
			if(roles.size() <= 2 && roles.size() != 0) {
				role1 = splitted[splitted.length-1]; // get last substring of Role.name
				
				if(!role1.isEmpty() && !role1.isBlank())
					role1 = role1.substring(1, role1.length() - 1); // trim parenthese bc i'm too lazy to RegEx
				else if(actNumber == 1)	noScenesMsg.setVisible(true); // user has no roles to display for act, display error
				
				if(roles.size() == 1) { break; } // no more roles to split
				else {
					role2 = splitted[splitted.length-1];
					
					if(!role2.isEmpty() && !role2.isBlank())
						role2 = role2.substring(1, role2.length() - 1);
					else if(actNumber == 2) noScenesMsg.setVisible(true);
				}
			}							
		}
			
		String str = "", line = "";
		
		try {
			BufferedReader reader;
			
			if(actNumber == 1) {
				if(role1=="") { // admin account forced check
					noScenesMsg.setVisible(true);
					return;
				}				
				reader = new BufferedReader(new FileReader(act1Path));
				while((line = reader.readLine()) != null) 
					if(line.contains(role1)) // append lines where role1 exists
						str += line + "\n";			
			}	
			else {
				if(role2== "") { // admin account forced check
					noScenesMsg.setVisible(true);
					return;
				}
				reader = new BufferedReader(new FileReader(act2Path));
				while((line = reader.readLine()) != null) 
					if(line.contains(role2)) // append lines where role2 exists
						str += line + "\n";
			}
				
			actTA.setText(str); // display inclusive Acts
			reader.close();
			
		} catch(IOException e) { e.printStackTrace(); }
	}
	
	// Sets Act Number label text to act @param
	public void setActNumber(int num) {
		actNumber = num;
		if (num == 1)
			actNumLbl.setText("Act I");
		else if(num == 2)
			actNumLbl.setText("Act II");
	}
	
	
}
