import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class SensorTask {

    public static void main(String[] args)
    {
        double[] data = {25.9, 25.1, 25.3, 25.5, 25.9, 25.0, 25.5, 25.4, 25.6, 25.5};
        Container container = new Container();
        for(int i = 0; i < 10; i++)
        {
            container.subcribeSensor(new Sensor());
        }
        container.receiveElements(data);

        container.printStatus();

        container.receiveElements(data);
        container.printStatus();

        container.receiveElements(data);
        container.printStatus();

        container.receiveElements(data);
        container.printStatus();

        container.receiveElements(data);
        container.printStatus();
    }


}

class Sensor
{
    public void setLastValue(double lastValue) {
        this.lastValue = lastValue;
    }

    private double lastValue;

    public void setCorrupted(boolean corrupted) {
        Corrupted = corrupted;
    }

    private boolean Corrupted = false;


    public boolean isCorrupted() {
        return Corrupted;
    }


    public double getLastValue() {
        return lastValue;
    }
}

class Container
{
    private LinkedHashMap<Sensor, Integer> container; // sensor : corrupted in a row
    private int elementsReceived = 0;
    private Mode mode;
    private File file;
    private Scanner sc;
    private double sum = 0;
    private double squared_sum = 0;

    public double getMean() {
        return mean;
    }

    private double mean;

    public double getVariance() {
        return variance;
    }

    private double variance;

    Container(String pathToFile)
    {
        container = new LinkedHashMap<>();
        file = new File(pathToFile);
        mode = Mode.FILE;
        double lastMeasureSum;

        try {
            sc = new Scanner(file);
        } catch (FileNotFoundException ex)
        {
            System.out.println("File not found");
            System.exit(1);
        }
    }

    Container()
    {
        container = new LinkedHashMap<>();
        mode = Mode.INTERNAL;

    }

    public void subcribeSensor(Sensor sensor)
    {
        container.put(sensor, 0);
    }

    public void receiveElements()
    {
        sum = 0;
        squared_sum = 0;
        elementsReceived = 0;
        for(int i = 0; i < container.size() - 1; i++) {
            if(!((Sensor) container.keySet().toArray()[elementsReceived]).isCorrupted()) {
                receiveElement();
                elementsReceived++;
            }
        }
        checkForCorruption();
    }
    public void receiveElements(double[] elements)
    {
        sum = 0;
        squared_sum = 0;
        elementsReceived = 0;
        for (double el : elements) {
            if(!((Sensor) container.keySet().toArray()[elementsReceived]).isCorrupted()) {
                receiveElement(el);
                elementsReceived++;
            }
        }
        System.out.println(elementsReceived);
        mean = sum / elementsReceived;
        variance = squared_sum / elementsReceived - mean * mean;
        checkForCorruption();
    }
    private void receiveElement()
    {
        double value = sc.nextDouble();
        sum += value;
        squared_sum += value * value;
        ((Sensor) container.keySet().toArray()[elementsReceived]).setLastValue(value);
    }
    private void receiveElement(double el)
    {
        //System.out.println(el);
        sum += el;
        squared_sum += el * el;
        //System.out.println(container.keySet().toArray()[elementsReceived]);
        ((Sensor)container.keySet().toArray()[elementsReceived]).setLastValue(el);
    }

    private void checkForCorruption()
    {
        for(Sensor sensor : container.keySet())
        {
            if(!sensor.isCorrupted()){
                if(checkForSingleCorruption(sensor))
                {
                    container.put(sensor, container.get(sensor) + 1);
                    if(container.get(sensor) >= 3) {
                        sensor.setCorrupted(true);
                    }
                }
                else
                {
                    container.put(sensor, 0);
                }
            }
        }
    }

    public void printStatus()
    {
        System.out.format("\nLast iteration received\nMean: %f\nVariance: %f\nStdDev: %f\n",
                this.getMean(), this.getVariance(), Math.sqrt(this.getVariance()));
        System.out.format("Sensors:\n");
        for(int i = 0; i < container.size(); i++)
            System.out.format("Sensor %d : %s\n", i,
                    ((Sensor)container.keySet().toArray()[i]).isCorrupted() ? "not avaliable" : "avaliable");
    }
    private boolean checkForSingleCorruption(Sensor sensor)
    {
        double value = sensor.getLastValue();
        System.out.format("\n%s %f", sensor, value);
        if(mean - 2*Math.sqrt(variance) > value || mean + 2*Math.sqrt(variance) < value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    enum Mode
    {
        INTERNAL,
        FILE
    }
}