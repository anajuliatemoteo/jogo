#include <iostream>
using namespace std;

int main()
{
	int opcao;
	double faturamento[10];
	int moto;
	double valor;
	double total;

	for(moto = 0; moto < 10; moto = moto + 1)
	{
		faturamento[moto] = 0;
	}

	do
	{
		cout << "0. Finalizar o dia" << endl;
		cout << "1. Informar valor" << endl;
		cout << "2. Listar valores" << endl;
		cout << "3. Listar comissoes" << endl;
		cout << "4. Informar moto que mais faturou" << endl;
		cout << endl;
		cout << "Escolha uma opcao: ";
		cin >> opcao;

		if (opcao == 1)
		{
			cout << "Qual a moto (1 a 10): ";
			cin >> moto;
			if (moto < 1 || moto > 10) {
				cout << "Moto invalida!" << endl;
				continue;
			}
			cout << "Qual o valor: ";
			cin >> valor;
			faturamento[moto - 1] += valor;
		}
		else if (opcao == 2)
		{
			total = 0;
			for(moto = 0; moto < 10; moto = moto + 1)
			{
				cout << "Moto: " << moto + 1 
					 << " - R$ " << faturamento[moto]
					 << endl;
				total += faturamento[moto];
			}
			cout << "Total: R$ " << total << endl;
			cout << endl;
		}
		else if (opcao == 3)
		{
			cout << "--- Comissoes (10%) ---" << endl;
			for (moto = 0; moto < 10; moto++)
			{
				double comissao = faturamento[moto] * 0.10;
				cout << "Moto " << moto + 1 << ": R$ " << comissao << endl;
			}
			cout << endl;
		}
		else if (opcao == 4)
		{
			double maior = faturamento[0];
			int indice = 0;
			for (moto = 1; moto < 10; moto++)
			{
				if (faturamento[moto] > maior)
				{
					maior = faturamento[moto];
					indice = moto;
				}
			}
			cout << "Moto que mais faturou: " << indice + 1 
				 << " com R$ " << maior << endl << endl;
		}
	}
	while (opcao != 0);
	
	return 0;
}
