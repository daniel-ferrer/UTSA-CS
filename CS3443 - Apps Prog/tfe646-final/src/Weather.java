import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;


/**
 * @author Daniel Ferrer-Sosa (tfe646)
 * The Weather class reads in data from weather.csv and prints a formatted forecast
 */
public class Weather {
	// class attributes
	String filename;
	HashMap<String, String> dailyWeather = new HashMap<String, String>();
	
	
	// default constructor
	public Weather() { }
	
	
	// constructor given @param values
	public Weather(String filename) {
		this.filename = filename;
	}
	
	// read file and populate HashMap
	public void loadForecast() {
		String line = null;
		String delim = ",";
		
		System.out.println("Weather forecast:\n");
		
		try {
			BufferedReader reader = new BufferedReader(new FileReader(filename));
			while((line = reader.readLine()) != null) {
				
				String splitted[] = line.split(delim);
				String weekDay = String.format("- %s: ", splitted[0]);
				String desc = String.format("%s degrees and %s", splitted[1], splitted[2]);
				
				dailyWeather.put(weekDay, desc);
			}
		} catch(IOException e) { e.printStackTrace(); }
	}
	

	@Override
	public String toString() {
		String ret = "";
		
		for(String i : dailyWeather.keySet()) {
			ret += i + dailyWeather.get(i) + "\n\n";
		}
		
		return ret;
	}
	
	
	public static void main(String[] args) {

		Weather week = new Weather("weather.csv");
		week.loadForecast();
		System.out.println(week);
	}
	

	/**
	 * @return the filename
	 */
	public String getFilename() {
		return filename;
	}

	/**
	 * @param filename the filename to set
	 */
	public void setFilename(String filename) {
		this.filename = filename;
	}

	/**
	 * @return the dailyWeather
	 */
	public HashMap<String, String> getDailyWeather() {
		return dailyWeather;
	}

	/**
	 * @param dailyWeather the dailyWeather to set
	 */
	public void setDailyWeather(HashMap<String, String> dailyWeather) {
		this.dailyWeather = dailyWeather;
	}
}
