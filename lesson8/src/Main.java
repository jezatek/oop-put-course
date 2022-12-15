public class Main
{
    public static void main(String[] args)
    {
        Weather weather=new Weather();
        assert ("18.23").equals(weather.toString());
        assert (18.23).equals(weather.toFloat());
        //assert ("18.24").equals(weather.toString());
        //assert (18.24).equals(weather.toFloat());
    }
}