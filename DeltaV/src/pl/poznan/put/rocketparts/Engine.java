package pl.poznan.put.rocketparts;

public class Engine {
	private float isp;
	private float mass;
	public float exhaust_v()
	{
		return (this.isp*9.8067f);
	}
	public float enginemass()
	{
		return (this.mass);
	}
	public Engine(float specificimpulse,float mass) throws IllegalArgumentException
	{
		this.isp=specificimpulse;
		if(this.isp<0)
			throw new IllegalArgumentException("Can't create engine with negative efficiency\n");
		if(this.isp>30057000.0f)
			throw new IllegalArgumentException("Can't create engine that is breaking laws of physics\n");
		else
		{
			this.mass=mass;
			if(this.mass<=0)
				throw new IllegalArgumentException("Mass of the engine must be positive\n");
		}
	}
	public String specification()
	{
		return String.format("ISP=%f\n",this.isp);
	}
}