package pl.poznan.put.samples;

import pl.poznan.put.rocketparts.*;

public class TestRockets {
	public void examples()
	{
		try
		{
			Engine F1= new Engine(263,42000);
			Engine J2= new Engine(421,1788);
			Engine stopper= new Engine(0,1000);
			//Engine falseEngine=new Engine(-1,0);
			Stage SIC=new Stage(2000000,F1,130000);
			Stage SII=new Stage(400000,J2,36000);
			Stage SIVB=new Stage(100000,J2,10000);
			Stage load=new Stage(0,stopper,10000);
			//Stage falseStage=new Stage(-1,F1,155);
			Rocket saturnV=new Rocket(load);
			saturnV.newBottomStage(SIVB);
			saturnV.newBottomStage(SII);
			saturnV.newBottomStage(SIC);
			System.out.printf("Saturn V %s\n",saturnV.deltaV());
			Rocket saturn0=new Rocket(load);
			System.out.printf("Tesla %s\n",saturn0.deltaV());
			Rocket rsaturnV=new Rocket(SIC);
			rsaturnV.newBottomStage(SII);
			rsaturnV.newBottomStage(SIVB);
			rsaturnV.newBottomStage(load);
			System.out.printf("Reversed Saturn V %s\n",rsaturnV.deltaV());
		}
		catch(IllegalArgumentException e)
		{
			System.out.printf("%s\n", e);
		}
	}

}