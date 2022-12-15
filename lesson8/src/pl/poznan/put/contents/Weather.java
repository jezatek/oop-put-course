public class Weather{
    final privite Forecast forecast=new Forecast.Fake();
    public float toFloat(){
        return forecast.temperature();
    }
    @Override
    public String toString(){
        return Float.toString(forecast.temperature());
    }
}