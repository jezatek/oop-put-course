package pl.poznan.put.rocketparts;

public interface RocketAssembly {
	String deltaV();
	void newBottomStage(Stage booster);
	public float totalmass();
}
