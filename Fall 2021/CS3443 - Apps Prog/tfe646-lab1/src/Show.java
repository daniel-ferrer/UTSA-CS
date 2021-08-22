
public class Show{
	// class attributes
	private String title;
	private CastMember[] cast;
	private int memberCount;
	
	// default constructor
	public Show() {}
	
	// constructor given param values
	public Show(String title, int memberCount) {
		this.title = title;
		this.cast = new CastMember[memberCount];
		this.memberCount = memberCount; // not needed ?
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
	
	
	public String toString() {
		
		return CastMember.class.toString();
	}
	
	public void addCastMember(CastMember member) {
		
	}
	

}
