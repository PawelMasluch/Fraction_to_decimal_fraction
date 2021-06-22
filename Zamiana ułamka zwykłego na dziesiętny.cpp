#include<iostream>
#include<vector>


using namespace std;


void ulamek_dziesietny(int licznik, int mianownik) // 0 <= licznik <= 10^9; 1 <= mianownik <= 10^6
{
	cout << licznik / mianownik; // czesc calkowita
	
	if( licznik % mianownik > 0 ) // jesli istnieje rozwiniecie dziesietne
	{
		cout << ",";
		
		licznik = licznik % mianownik;
		
		//cout << "\nlicznik = " << licznik << endl;
		
		vector <int> rozwiniecie; // kolejne cyfry rozwiniecia dziesietnego
		int ile = 0; // ile cyfr w rozwinieciu jest aktualnie w wektorze
		int nr_pozycji[mianownik]; // ktorej cyfrze rowiniecia odpowiada dana roznica (0...mianownik-1) w dzieleniu pisemnym
		
		for(int r=0; r<mianownik; ++r){
			nr_pozycji[r] = -1; // dana roznica nie wystapila
		}
		
		// Warunki poczatkowe
		int akt_pozycja = 0; // nr pozycji dla aktualnej cyfry rozwiniecia
		int akt_roznica = licznik;
		int akt_cyfra;
		
		while( nr_pozycji[akt_roznica] == -1 ) // dopoki nie powtorzyla sie roznica
		{
			//cout << "\nakt_pozycja: " << akt_pozycja << endl;
			//cout << "akt_roznica: " << akt_roznica << endl;
			
			if( akt_roznica == 0 ) // ulamek ma rozwiniecie skonczone
			{
				// wypisujemy rozwiniecie
				for(int i=0; i<ile; ++i)
				{
					cout << rozwiniecie[i];
				}
		
				return; // konczymy dzialanie calej procedury
			}
			
			nr_pozycji[akt_roznica] = akt_pozycja;
			akt_cyfra = (10*akt_roznica) / mianownik;
			rozwiniecie.push_back( akt_cyfra );    
			
			//cout << "akt_cyfra: " << akt_cyfra << endl;
			
			++ile;    ++akt_pozycja;
			
			akt_roznica = 10*akt_roznica - akt_cyfra*mianownik;
		}
		
		
		
		// wypisywanie rozwiniecia okresowego
		
		// najpierw "rozbieg"
		for(int i=0; i<nr_pozycji[akt_roznica]; ++i)
		{
			cout << rozwiniecie[i];
		}
		
		
		// teraz czesc okresowa
		cout << "(";
		for(int i=nr_pozycji[akt_roznica]; i<ile; ++i)
		{
			cout << rozwiniecie[i];
		}
		cout << ")";
	}
}


int main()
{
	int licznik, mianownik; // 0 <= licznik <= 10^9; 1 <= mianownik <= 10^6
	
	cout << "Podaj licznik: ";
	cin >> licznik;
	
	cout << "\nPodaj mianownik: ";
	cin >> mianownik;
	
	cout << endl << licznik << " / " << mianownik << " = ";    ulamek_dziesietny( licznik, mianownik ); 
	
	return 0;
}
