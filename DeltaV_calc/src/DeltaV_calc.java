import pl.poznan.put.rocketparts.*;
import pl.poznan.put.samples.*;
import java.util.Scanner;

public class DeltaV_calc{
	public static void main(String[] args) {
		Scanner cin= new Scanner(System.in);
		int choice=9;
		Engine engine=new Engine(200,1000);
		Stage stage=new Stage(12740,engine,1300);
		Rocket rocket=new Rocket(stage);
		float input1;
		float input2;
		TestRockets example=new TestRockets();
		while(choice!=-1)
		{
			System.out.printf("Choose options:\n"
							+ "0: test rockets\n"
							+ "1: create your own engine\n"
							+ "2: create your own stage\n"
							+ "3: create new one-stage rocket\n"
							+ "4: add one stage to a rocket\n"
							+ "5: check delta v of the saved rocket\n"
							+ "-1: exit application\n");
			choice=cin.nextInt();
			switch(choice)
			{
				case 0:
					example.examples();
				break;
				case 1:
					try
					{
						System.out.printf("Write ISP and mass of the engine\n");
						input1=cin.nextFloat();
						input2=cin.nextFloat();
						engine=new Engine(input1,input2);
					}
					catch(IllegalArgumentException e)
					{
						System.out.printf("%s\n", e);
					}
					
				break;
				case 2:
					try
					{
						System.out.printf("Write fuel and tankmass of the stage\n");
						input1=cin.nextFloat();
						input2=cin.nextFloat();
						stage = new Stage(input1,engine,input2);
					}
					catch(IllegalArgumentException e)
					{
						System.out.printf("%s\n", e);
					}
				break;
				case 3:
					rocket=new Rocket(stage);
				break;
				case 4:
					rocket.newBottomStage(stage);
				break;
				case 5:
					System.out.printf("%s\n",rocket.deltaV());
				break;
			}
		}
		cin.close();
	}
}