
import java.util.*;

public class BracketsSequence {


    public static void main(String[] args) {
        int mode = 1;
        if(mode == 1) {
            Scanner sc = new Scanner(System.in);
            int code = isStringBracketsFine(sc.nextLine());
            if (code == 0)
                System.out.println("Success");
            else {
                System.out.println(code);
            }
        }
        else
        {
            int code = isStringBracketsFine("[]([]");
            if (code == 0)
                System.out.println("Success");
            else {
                System.out.println(code);
            }
            runTests();
        }
        /*System.out.println("\nTest done with code " + code);
        runTests();*/
    }

    static int isStringBracketsFine(String sequence) {
        Stack<Character> bracketsStack = new Stack<>();
        Stack<Integer> numberOfBracketStack = new Stack<>();
        int currentOpeningBracketIndex = 0;
        char[] charSequence = sequence.toCharArray();
        char[] validOpeningBrackets = {'{', '[', '('};
        List<Character> validCharacters = Arrays.asList('{', '[', '(', '}', ']', ')');
        int currentAnyBracketIndex = 0;
        char topBracket;
        for (Character symbol : charSequence) {
            currentAnyBracketIndex++;
            currentOpeningBracketIndex++;
            if(!validCharacters.contains(symbol)) {
                //currentOpeningBracketIndex++;
                continue;
            }
            //currentAnyBracketIndex++;
            if (symbol == validOpeningBrackets[0] || symbol == validOpeningBrackets[1] || symbol == validOpeningBrackets[2])
            {
                bracketsStack.push(symbol);
                //currentOpeningBracketIndex++;
                numberOfBracketStack.push(currentOpeningBracketIndex);
            }
            else
            {
                if(bracketsStack.isEmpty()) return currentAnyBracketIndex;
                topBracket = bracketsStack.pop();
                numberOfBracketStack.pop();
                if(topBracket == '{' && symbol != '}'
                        || topBracket == '[' && symbol != ']'
                        || topBracket == '(' && symbol != ')')
                {
                    return currentAnyBracketIndex;
                }
            }
                //System.out.println(bracketsStack);
                //System.out.println(numberOfBracketStack);
        }
        if(bracketsStack.isEmpty())
            return 0;
        else
            //return
            return numberOfBracketStack.peek();


    }


    static void runTests()
    {
        assert isStringBracketsFine("([](){([])})") == 0;
        assert isStringBracketsFine("()[]}") == 5;
        assert isStringBracketsFine("{{[()]]") == 7;
        assert isStringBracketsFine("{{{[][][]") == 3;
        assert isStringBracketsFine("{*{{}") == 3;
        assert isStringBracketsFine("[[*") == 2;
        assert isStringBracketsFine("{*}") == 0;
        assert isStringBracketsFine("{{") == 2;
        assert isStringBracketsFine("{}") == 0;
        assert isStringBracketsFine("") == 0;
        assert isStringBracketsFine("}") == 1;
        assert isStringBracketsFine("*{}") == 0;
        assert isStringBracketsFine("{{{**[][][]") == 3;
        assert isStringBracketsFine("[]([]") == 3;
    }

}
