package pl.poznan.put.rocketparts;

public class Rocket implements RocketAssembly {
	private Stage stages[];
	private int nrstages;
	public Rocket(Stage booster)
	{
		this.stages=new Stage[10];
		this.nrstages=1;
		stages[0]=booster;
	}
	@Override
	public float totalmass()
	{
		return stages[nrstages-1].totalmass();
	}
	@Override
	public String deltaV()
	{
		float result=0.0f;
		float stageDeltav=0;
		String explanation="DeltaV for every stage:\n";
		float mass=0;
		for(int i=0;i<nrstages;i++)
		{
			mass+=stages[i].totalmass();
			stageDeltav=(stages[i].Vexhaust()*(float)(Math.log(mass/(mass-stages[i].fuel()))));
			result+=stageDeltav;
			explanation+=("Stage "+i+": "+stageDeltav+"\n");
		}
		explanation+=("Whole rocket DeltaV="+result+"\n");
		return explanation;
	}
	@Override
	public void newBottomStage(Stage booster) throws IllegalArgumentException
	{
		if(nrstages==10)
			throw new IllegalArgumentException("Rocket can have maximum 10 stages\n");
		else
		{
			this.totalmass();
			this.stages[this.nrstages]=booster;
			nrstages++;
		}
	}
}