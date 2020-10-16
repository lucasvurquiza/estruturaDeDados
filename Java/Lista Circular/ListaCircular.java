
public class ListaCircular {

	private No primeiroNo;
	private No ultimoNo;

	public void inserirNoFinal(Object elemento) {
		No novoNo = new No(primeiroNo, elemento);
		novoNo.setProximo(null);

		if (isEmpty()) {
			primeiroNo = novoNo;
		} else {
			No atualAnterior = primeiroNo;
			while (atualAnterior.getProximo() != null) {
				atualAnterior = atualAnterior.getProximo();
			}
			
			ultimoNo = novoNo;
			atualAnterior.setProximo(ultimoNo);
		}
	}
	
	public void removerNoFinal() {
		if (!isEmpty()) {

			if (primeiroNo.getProximo() == null) {
				removerInico();
				return;
			}
			No primeiroNoTemp = primeiroNo;
			while (primeiroNoTemp.getProximo().getProximo() != null) {
				primeiroNoTemp = primeiroNoTemp.getProximo();
			}

			ultimoNo = primeiroNoTemp;
			ultimoNo.setProximo(null);

		}
	}
	
	public int buscarNo(Object elemento) {
		No atualNo = primeiroNo;
		int i = 0;
		while (atualNo != null && atualNo.getElemento() != elemento) {
			atualNo = atualNo.getProximo();
			i++;
		}

		if (atualNo != null) {
			return i;
		}

		return -1;
	}
	
	public boolean isEmpty() {
		return primeiroNo == null;
	}

	public void removerInico() {
		if (!isEmpty())
			primeiroNo = primeiroNo.getProximo();
	}

	public void listarLista() {
		No listaTemp = primeiroNo;
		int i = 0;
		if (isEmpty()) {
			System.out.print("Lista Vazia!\n");
			return;
		}
		while (listaTemp != null) {
			System.out.print(i++ + " - " + listaTemp.getElemento() + "\n");
			listaTemp = listaTemp.getProximo();
		}
	}
}
