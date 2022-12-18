package pl.poznan.put.rocketparts;

public class Stage implements Segment{
	private final float drymass;
	private final float fuelmass;
	private final Engine lfe;
	public Stage(float fuel,Engine liquidfuelengine,float tankmass) throws IllegalArgumentException
	{
		if(fuel<0)
			throw new IllegalArgumentException("Mass of the fuel can't be negative\n");
		else if(tankmass<=0)
			throw new IllegalArgumentException("Tank must have a mass\n");
		else
		{
			this.lfe=liquidfuelengine;
			this.fuelmass=fuel;
			this.drymass=tankmass+liquidfuelengine.enginemass();
		}
	}
	public float totalmass()
	{
		return fuelmass+drymass;
	}
	public float fuel()
	{
		return fuelmass;
	}
	public float Vexhaust()
	{
		return lfe.exhaust_v();
	}
	@Override
	public Stage addedfuel(float mass) throws IllegalArgumentException
	{
		if(mass+this.fuelmass<0)
			throw new IllegalArgumentException("Mass of the fuel can't be negative\n");
		else
			return new Stage(this.fuelmass+mass,this.lfe,this.drymass-this.lfe.enginemass());
	}
	@Override
	public String specification()
	{
		return String.format("Mass of fuel: %f, %s",
				this.fuelmass,this.lfe.specification());
	}
}