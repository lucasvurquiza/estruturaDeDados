
public class App {
   public static void main(String args[]) {
	   ListaCircular listaEncadeada = new ListaCircular();
	   listaEncadeada.listarLista();
	   listaEncadeada.inserirNoFinal(10);
	   listaEncadeada.inserirNoFinal(5);
	   listaEncadeada.listarLista();
	   System.out.println("");
	   listaEncadeada.listarLista();
	   System.out.println("\n" +listaEncadeada.buscarNo(10));
   }
}
