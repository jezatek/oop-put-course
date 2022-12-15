public interface Forecast{
	public float temperature();
	final class Fake implements Forecast {
		@Override
	        public float tempreature(){
        	    return 18.23;
        	}
	}
}