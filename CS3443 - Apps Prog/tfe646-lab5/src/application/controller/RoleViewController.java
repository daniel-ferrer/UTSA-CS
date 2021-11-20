package application.controller;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

import application.model.Role;
import application.model.User;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;

public class RoleViewController implements Initializable  {
	@FXML
	private ImageView hamiltonImg;
	@FXML
	private Label nameLbl, rolesLbl, displayUsernameLbl;
	@FXML
	private Button act1Btn, act2Btn, logoutBtn;
	@FXML
	private TextArea nameTA, roleTA;
	
	// Helper vars
	private final String viewPath = "/main/resources/fxml/view/ActView.fxml";
	private final String loginPath = "/main/resources/fxml/view/Login.fxml";
	private User _usr; // global User obj will be used to populate labels in view

	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {	}
	
	// Event Listener on Button[#act1Btn].onAction
	// Will send user to ActView.fxml for Act I
	@FXML
	public void viewActOne(ActionEvent event) {
		Node node = (Node) event.getSource();
		Stage stage = (Stage) node.getScene().getWindow();
		try {
			FXMLLoader loader = new FXMLLoader (getClass().getResource(viewPath));
			Parent root = (Parent) loader.load();
			ActViewController controller = loader.getController();
			controller.setActNumber(1);
			controller.intakeUser(_usr);
			Scene scene = new Scene(root, 800, 800);
			stage.setScene(scene);
			stage.setTitle("Act I");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	// Event Listener on Button[#act2Btn].onAction
	// Will send user to ActView.fxml for Act II
	@FXML
	public void viewActTwo(ActionEvent event) {
		Node node = (Node) event.getSource();
		Stage stage = (Stage) node.getScene().getWindow();
		try {
			FXMLLoader loader = new FXMLLoader (getClass().getResource(viewPath));
			Parent root = (Parent) loader.load();
			ActViewController controller = loader.getController();
			controller.setActNumber(2);
			controller.intakeUser(_usr);
			Scene scene = new Scene(root, 800, 800);
			stage.setScene(scene);
			stage.setTitle("Act II");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
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
	
	// Method will populate RoleView.fxml objects based on user
	public void intakeUser(User user) {
		String _str = "";
		ArrayList<Role> roles = user.getRoles();
		
		nameTA.setText(user.getName());
		displayUsernameLbl.setText(user.getUsername());
	
		if(roles != null) {
			for(Role role: roles) {
				_str += role.getName() + "\n";
			}
			roleTA.setText(_str);
		}
		_usr = user;
			
	}
	

}
