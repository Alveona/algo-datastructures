import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TreeHeight {
    /*
        I just realised there is no equivalent to C's static variables in function (for example,
        in recursive functions), there is only class static variables
     */
    //static int currentRoot = 0;
    static int rootOfTree;

    public static void main(String[] args)
    {
        //runTests();
        Scanner sc = new Scanner(System.in);
        int numberOfNodes = sc.nextInt();
        int[] listOfParents = new int[numberOfNodes];
        for(int i = 0; i < numberOfNodes; i++)
        {
            listOfParents[i] = sc.nextInt();
        }
        countTreeHeight(numberOfNodes, listOfParents);
    }

    static void runTests()
    {
        assert countTreeHeight(5, new int[]{4, -1, 4, 1, 1}) == 3;
        assert countTreeHeight(5, new int[]{-1, 0, 4, 0, 3}) == 4;
        assert countTreeHeight(10, new int[]{9, 7, 5, 5, 2, 9, 9, 9, 2, -1}) == 4;
    }
    static int countTreeHeight(int numberOfNodes, int[] listOfParents)
    {

        List<ArrayList<Integer>> listOfChildren = transformListOfParentsToListOfChildren(numberOfNodes, listOfParents);
        int height = recursiveHeightCounter(rootOfTree, listOfChildren);
        System.out.println(height);
        return height;
    }
    static int recursiveHeightCounter(int rootIndex, List<ArrayList<Integer>> listOfChildren)
    {
        //static int currentRoot = 0; // read note in the beginning of file
        int height = 1;
        //System.out.println("\nIteration:");
        for(Integer child : listOfChildren.get(rootIndex))
        {
            //System.out.println(child);
            height = Math.max(height, 1 + recursiveHeightCounter(child, listOfChildren));
        }
        //System.out.format("Height is %d\n", height);
        return height;
    }
    static List<ArrayList<Integer>> transformListOfParentsToListOfChildren(int numberOfNodes, int [] listOfParents)
    {
        List<ArrayList<Integer>> listOfChildren = new ArrayList<>();
        /*System.out.println("List of parents:");
        for(int i = 0; i < numberOfNodes; i++)
        {
            System.out.format("%2d ", i);
        }
        System.out.println();
        for(int i = 0; i < numberOfNodes; i++)
        {
            System.out.format("%2d ", listOfParents[i]);
        }*/


        //System.out.println("\nList of children: ");
        for(int i = 0; i < numberOfNodes; i++)
        {
            listOfChildren.add(i, new ArrayList<Integer>());
        }

        int rootIndex = 0;
        for(int i = 0; i < numberOfNodes; i++)
        {
            if(listOfParents[i] != -1)
                listOfChildren.get(listOfParents[i]).add(i);
            else
                rootIndex = i;
        }
        //System.out.format("Root is %d\n", rootIndex);
        for(int i = 0; i < numberOfNodes; i++)
        {
            //System.out.format("%d - ", i);
            for(int j = 0; j < listOfChildren.get(i).size(); j++)
            {
                //System.out.format("%d ", listOfChildren.get(i).get(j));
            }
            //System.out.println();
        }
        rootOfTree = rootIndex;
        return listOfChildren;
    }
}
