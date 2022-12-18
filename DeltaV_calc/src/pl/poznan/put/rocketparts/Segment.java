package pl.poznan.put.rocketparts;

public interface Segment {
	Segment addedfuel(float mass);
	String specification();
	public float totalmass();
}
