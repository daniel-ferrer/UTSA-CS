/**
 * This class represents a Show object
 * which contains a title string, CastMember objects and their methods, and a toString() method
 * 
 * @author Daniel Ferrer-Sosa (tfe646)
 * 
 */
public class Show extends CastMember{
	// class attributes
	private String title;
	private CastMember[] cast;
	private int memberCount;
	private int cnt; // count int to keep track of array pos
	
	// default constructor
	public Show() {}
	
	// constructor given param values
	public Show(String title, int memberCount) {
		this.title = title; // title of the show
		this.cast = new CastMember[memberCount];
		this.memberCount = memberCount; // redundant declaration, not needed ?
		cnt = 0;
	}
	
	// getters and setters
	public String getTitle() {
		return title;
	}
	
	public void setTitle(String title) {
		this.title = title;
	}
	
	public CastMember[] getCast() {
		return cast;
	}
	
	public void setCast(CastMember[] cast) {
		this.cast = cast;
	}
	
	public int getMemberCount() {
		return memberCount;
	}
	
	public void setMemberCount(int memberCount) {
		this.memberCount = memberCount;
	}
	
	// adds CastMember object to CastMember array
	public void addCastMember(CastMember member) {
		if(cnt < cast.length) { // if count of cast members is less than cast.length
			cast[cnt] = member; // add CastMember to cast array at current pos
			cnt++; // increment count of current cast members
		}
	}
	
	// prints Show attributes and calls upon toString() method in
	// CastMember class to return info as string
	public String toString() {
		String str = "";
		str = "Show: " + title + "\n";
		str += memberCount + " cast members\n";
		
		if(cast.length > 0) {
			for(int i = 0; i < cast.length; i++) {
				str += cast[i].toString();
			}
		}
		
		return str;		
	}
}
