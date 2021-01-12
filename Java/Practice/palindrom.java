
public class palindrom{
    public static void main(String[] args){
        System.out.println(isPalindrome("Madam, I'm Adam!"));
    }
    
    public static boolean isPalindrome(String text) {
        text = text.replaceAll("[^a-zA-Z0-9]", "");
        text = text.toLowerCase();
        for(int i = 0; i != text.length()/2; i++){
            if(text.charAt(0 + i) != text.charAt(text.length() - 1 - i)){
                return false;
            }            
        }
        return true;
    }
}
