import java.io.*;
import java.util.*;

public class lab1 {
	public static void main(String [] args) {

		String nomeDoArquivo1 = "pib.txt";
		String nomeDoArquivo2 = "regioes.txt";

		String linha = null;
		String[] lsplit;
		HashMap<String,Double> estados = new HashMap<>();
		double total = 0.0, soma = 0.0;

		try {

			FileReader fileReader = new FileReader(nomeDoArquivo1);
			BufferedReader bufferedReader = new BufferedReader(fileReader);

			while ((linha = bufferedReader.readLine()) != null) {
				lsplit = linha.split(";");
				estados.put(lsplit[0], Double.parseDouble(lsplit[1]));
				total += estados.get(lsplit[0]);
			}   

			bufferedReader.close();

		} catch (FileNotFoundException ex) {
			System.out.println("Arquivo inexistente: '" + nomeDoArquivo1 + "'");       
		} catch (IOException ex) {
			System.out.println("Erro lendo o arquivo '" + nomeDoArquivo1 + "'");      
		}

		for (String estado : estados.keySet()) {
			System.out.println(String.format("%20s (~%-4.1f%%) : %.1f", 
						estado, (estados.get(estado) * 100) / total,
						estados.get(estado)));
		}

		System.out.println(String.format("%20s ( 100 %%) : %.1f", "Total", total));

		String arquivoDeSaida = "saida.txt";

		try {

			FileReader fileReader = new FileReader(nomeDoArquivo2);
			BufferedReader bufferedReader = new BufferedReader(fileReader);

			FileWriter fileWriter = new FileWriter(arquivoDeSaida);
			BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

			bufferedWriter.write(bufferedReader.readLine() + ";");
			while ((linha = bufferedReader.readLine()) != null) {
				if (linha.isBlank()) {
					bufferedWriter.write(soma + "\n");
					soma = 0.0;
					linha = bufferedReader.readLine();
					bufferedWriter.write(linha + ";");
					continue;
				}
				soma += estados.get(linha);
			}   
			bufferedWriter.write(String.valueOf(soma));

			bufferedReader.close();
			bufferedWriter.close();

		} catch (FileNotFoundException ex) {
			System.out.println("Arquivo inexistente: '" + nomeDoArquivo1 + "'");        
		} catch (IOException ex) {
			System.out.println("Erro lendo o arquivo '" + nomeDoArquivo1 + "'");        
		}

	}
}
