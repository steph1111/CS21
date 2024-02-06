public class Main {
    public static void main(String[] args) {
        LinkedList my_list = new LinkedList();
        for (int i = 0; i < 5; i++) {
            my_list.push_back("hello");
        }
        System.out.println(my_list);
    } 
}