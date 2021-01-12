public class binary_flip{

    public static void main(String[] args) {
        System.out.print(flipBit(7,3));
    }
    
    public static int flipBit(int value, int bitIndex) {
        return  value ^ (1 << bitIndex - 1);
    } 
}   
