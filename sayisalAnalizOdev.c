/* Say�sal Analiz

Burak Boz

Y�ntemler ve giri� kodlar�
1 -> Yar�ya b�lme y�ntemi +
2 -> Grafik y�ntemi +
3 -> Newton Raphson y�ntemi +
4 -> Regula false y�ntemi +
5 -> Matrisin inversi
6 -> Gauss eleminasyon y�ntemi
7 -> Trapez y�ntemi
8 -> Simpson y�ntemi
9 -> N�merik t�rev

10 -> Programdan ��k��


*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int enbuyder,i=0,j,k=0,t,sonuc=0,bitir,sayac,devam,cikis=1,menu,satir,sutun,y,n,cik,degisken;
	static float pol[10];
	float x[50],X0=0,x1=0,x2,Xn,a,b,c,fa,fb,epsilon,delta,bolum,m=0,eleman,p,r,h,sum=0,cevap,toplam=0,tek=0,cift=0,ileri,geri,merkezi,sayim=0.0;
	float fx0=0,fdx0=0,fx1=0,fx2=0;
	float matrisA[75][75],matrisB[75][75];
	static float fX0[75],fX01[75],fX02[75],x0[75],Y[75],xc[75],fc[75],denklem[25];
	while (cikis)
	{
		printf("Kok Bulma Yontemleri:\n\n1)Yariya Bolme Yontemi\n2)Grafik Yontemi\n3)Newton Raphson Yontemi\n4)Regula False Yontemi\n");
		printf("\nMatris Islemleri:\n\n5)Matrisin Inversinin Alinmasi\n");
		printf("\nDogrusal Denklem Takimlarinin Cozumu:\n\n6)Gauss Eleminasyon Yontemi\n");
		printf("\nNumerik Integral:\n\n7)Trapez Yontemi\n8)Simpson Yontemi\n");
		printf("\nNumerik Turev:\n\n9)Numerik Turev\n\n");
		printf("Not:Uygulamadan cikmak icin 10'a basiniz..\n\n");
		printf("Lutfen Kullanacaginiz Yontemin Numarasini Giriniz: ");
		scanf("%d",&menu);
		switch(menu){
			case 1://Yar�ya B�lme y�ntemi
			system("CLS");
			printf("\n\n\t\t\t Yariya Bolme Yontemi");
			printf("\n\n\nDenklemin en buyuk derecesi : ");//Denklemin derecesi kullan�c�dan isteniyor
			scanf("%d",&enbuyder);//En b�y�k de�er okunuyor
			for(i=enbuyder;i>=0;i--)//Katsay�lar Kullan�c�dan isteniyor
    		{
        		printf("\nx^%d.terimin katsayisi :",i);
        		scanf("%f",&pol[i]);//Katsay�lar dizinin i�erisine aktar�l�yor
    		}
			printf("\nDenklem : ");
    		for(i=enbuyder;i>=0;i--)//Kullan�c�n�n girdi�i denklem ekrana yazd�r�l�yor
    		{
        		printf(" %.3fx^%d",pol[i],i);
    		}
    		printf("\n\nAlt Sinir Degeri : ");//Alt s�n�r de�eri kullan�c�ndan isteniyor ve a de�i�keni i�erisine at�l�yor
			scanf("%f",&a);
			printf("\nUst Sinir Degeri : ");//�st s�n�r de�eri kullan�c�dan isteniyor ve b de�i�keni i�erisine at�l�yor
			scanf("%f",&b);
			printf("\nEpsilon Degeri : ");//Hata pay� kullan�c�dan isteniyor ve epsilon de�i�keninin i�ine at�l�yor
			scanf("%f",&epsilon);
			cik=1;
			printf("\n\n     A          F(A)           B           F(B)            C           F(C)\n");
			printf("--------------------------------------------------------------------------------");
			do{
				fa=0;
				fb=0;
				for (i=enbuyder;i>=0;i--)//Alt s�n�r ve �st s�n�r de�erlerinin hesaplanmas� ve f(a) ve f(b) de�i�kenleri i�erisine eklenmesi
				{
					fa+=pol[i]*(pow(a,i));
					fb+=pol[i]*(pow(b,i));
				}
				printf("\n %6.4f        %6.4f        %6.4f       %6.4f    ",a,fa,b,fb);//Hesaplanan de�erlerin fonksiyona girilen de�erler ile birlikte ekrana yazd�r�lmas�
				if (fa*fb<0)//E�er fonksiyon ��kt�lar�n�n �arp�mlar� negatifse a ve b aral���nda k�k vard�r ve ortalama hesaplan�r
				{
					xc[k]=(a+b)/2;//Ortalama xC dizisi i�inde tutulacak
					for (i=enbuyder;i>=0;i--)
					{
						fc[k]+=pol[i]*(pow(xc[k],i));//pow �s almak i�in
					}
				}
				if (fa*fc[k]<0)//E�er �arp�mlar negatifse b�y�k de�eri ortalama olarak g�ncelliyoruz
				{
					b=xc[k];
				}
				else//De�ilse k���k de�eri ortalama olarak g�ncelliyoruz
				{
					a=xc[k];
				}
				printf("     %6.4f       %6.4f",xc[k],fc[k]);//�terasyondan ��kan de�eri ekrana yazd�r�yoruz
				if ((fabs(xc[k]-xc[k-1])<=epsilon)||(fabs(fc[k]-fc[k-1])<=epsilon))//Ortalamalar aras�ndaki fark mutlak de�erce hata pay�ndan k���kse d�ng�den ��k�yoruz
				{
					cik=0;
				}
			  k++;
		   }while(cik==1);//cik de�eri 0 ise d�ng�den ��k�lacak
			printf("\n\nDenklemin koku : %f", xc[k-1]);//K�k ekrana yaz�l�yor
			printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;

		case 2://Grafik y�ntemi
		    system("CLS");
				printf("\n\n\t\t\t Grafik Yontemi");
				printf("\n\n\nDenklemin en buyuk derecesi : ");
				scanf("%d",&enbuyder);//Kullan�c�dan denklemin derecesi isteniyor.
				for(i=enbuyder;i>=0;i--)//Denklemin olu�turulabilmesi i�in kullan�c�dan katsay�lar al�n�yor.
    			{
        			printf("\nx^%d.terimin katsayisi :",i);
        			scanf("%f",&pol[i]);//Katsay�lar pol dizisi i�erisinde tutulacak
    			}
				printf("\nDenklem : ");//Olu�turulan denklem ekrana yaz�l�yor.
    			for(i=enbuyder;i>=0;i--)
    			{
        			printf(" %.3fx^%d",pol[i],i);
    			}
				printf("\n\nX0 baslangic degeri : ");//Ba�lang�� de�eri kullan�c�dan al�n�yor
    			scanf("%f",&x0);
    			printf("\nDelta x degeri :");//deltaX de�eri kullan�c�dan al�n�yor
    			scanf("%f",&delta);
    			printf("\nEpsilon degeri :");//Hata pay� kullan�c�dan al�n�yor.
    			scanf("%f",&epsilon);
    			t=0;//T de�i�keni k�k�n bulunmas�nda index olarak kullan�lacak
    			bitir=1;//While'�n sonu�land�r�lmas� i�in bool de�er olarak kullan�l�yor
    			sayac=1;//�terasyon say�s� saya� i�erisinde tutulacak
    			//Gerekli fonksiyonun ve de�erlerin kullan�c�dan al�nmas� tamamland�
   				do
    			{
			   	    devam=0;
			        printf("\n\n       %d. Iterasyon\n",sayac);
					printf("     X              F(x)\n");
					printf("---------------------------");//Bu b�l�mde iterasyon say�s� ekrana yazd�r�l�yor.
					while(devam!=1)//Hesaplamalar bu while i�erisinde yap�l�yor.
					{
			            for(i=enbuyder;i>=0;i--)//De�er  fonksiyon i�erisine konularak f(x) �eklinde hesaplan�yor.
			            {
			                fX0[t]+=pol[i] * (pow(x0[t],i)) ;
			            }
			            printf("\n%10.6f",x0[t]);
						printf("	%10.6f",fX0[t]);
						bolum=fX0[t]/fabs(fX0[t]);//��aretin de�i�ip de�i�medi�ini kontrol etmek i�in kendine b�l�yoruz
						x0[t+1]=x0[t]+delta;//x0 De�erinin bir sonraki de�erini hesaplamak i�in �zerinde delta de�eri ekleniyor
						if (sonuc==0)//Sonu� de�eri ba�lang��ta 0 olarak ilklendirildi. Bu kod sadece ilk ad�mda �al��acak
						{
							sonuc=bolum;
						}
						if(sonuc!=bolum)//Sonu� e�er b�l�m de�erine e�it de�ilse �artlar� kontrol edece�iz. Bu kod ilk ad�mda �al��may�p ikinci ad�mda �al��mas� i�in yaz�ld�
						{
							if ((fabs(fX0[t]-fX0[t-1])<=epsilon)||(delta<=epsilon))//Bulunan de�er ve bir �nceki de�erin fark� hata pay�ndan mutlak de�erce k���kse
						    {													   //ya da deltaX de�eri hata pay�dan k���kse d�g�den ��k�l�yor.
							  bitir=0;	//�artlar sa�land�ysa k�k bulunmu�tur
						    }
						    devam=1;
							x0[t+1]=x0[t]-delta;	//x0�n bir sonraki de�eri hesaplan�yor
							delta/=2;
						}
						t++;
				   }
				   sayac++;
			}while(bitir==1);
			
			printf("\n");
			printf("\nKok => %f", x0[t-1]);//t de�eri k�kten bir sonraki de�eri index'ledi�i i�in bir �nceki de�er bizim buldu�umuz k�k de�eridir.
			printf("\n--------------------------");
			printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;

		case 3://Newton Raphson y�ntemi
			  		    system("CLS");
			printf("\n\n\t\t\t Newton Raphson Yontemi");
			printf("\n\n\nDenklemin en buyuk derecesi : ");
			scanf("%d",&enbuyder);//Kullan�c�dan denklemin derecesi al�nd�
			for(i=enbuyder;i>=0;i--)//Bu for i�erisinde denklemin katsay�lar� kullan�c�dan al�nd� ve pol dizisi i�erisinde tutuluyor.
    		{
        		printf("\nx^%d.terimin katsayisi :",i);
        		scanf("%f",&pol[i]);
    		}
			printf("\nDenklem : ");//Al�nan denklem ekrana yazd�r�ld�.
    		for(i=enbuyder;i>=0;i--)
    		{
        		printf(" %.3fx^%d",pol[i],i);
    		}
			printf("\n\nX0 baslangic degeri : ");
		    scanf("%f",&X0);//Ba�lang�� de�eri kullan�c�dan al�nd�
		    printf("\nEpsilon degeri :");
		    scanf("%f",&epsilon);//Hata pay� kullan�c�dan al�nd�
			printf("\n Iterasyon    X0         X1  ");
		    printf("\n ------------------------------");
			k=0;
			do
		    {
		            k++;//�terasyon say�s� k de�i�keni i�erisinde tutuluyor.
		            fx0=fdx0=0;//X de�eri fonksiyona konacak ve fx0 de�i�keni i�erisinde tutulacak, T�rev de�eri ise fdx0 de�i�keni i�erisinde tutulacak
		            for(i=enbuyder;i>=1;i--)
		            {
		                fx0+=pol[i] * (pow(X0,i)) ;//x de�eri fonksiyonda yerine konularak hesaplan�yor.
		            }
		            fx0+=pol[0];
		            for(i=enbuyder;i>=0;i--)
		            {
		                fdx0+=pol[i]* (i*pow(X0,(i-1)));//fonksiyonun t�revi al�narak x de�eri fonksiyonda yerine konuluyor ve fdx0 de�eri hesaplan�yor
		            }
		            m=x1;//x1 de�eri ge�ici olarak m de�i�keni i�erisinde saklan�yor.
		            x1=(X0-(fx0/fdx0));//Bir sonraki de�er hesaplan�yor
		            printf("\n %d         %.6f  %.6f ",k,X0,x1);//s�ras�yla iterasyon,x0,x1 de�erleri ekrana yazd�r�ld�
		            X0=x1;
			}while((fabs(m - X0))>=epsilon);//E�er �nceki ad�mda bulunan x1 de�eri(yani m) x0 de�erinden ��karl�l�yor ve mutlak de�erce epsilon de�erinden b�y�k
											// olup olmad��� kontrol ediliyor. E�er epsilon de�erinden b�y�kse ad�mlar tekrarlan�yor. K���kse k�k bulunmu�tur.
		    printf("\n\nDenklemin Koku : %f",x1);//Bulunan sonu� ekrana yazd�r�l�yor.
		    printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;

		case 4://Regula False y�ntemi
		    system("CLS");
			printf("\n\n\t\t\t Regula False Yontemi");
			printf("\n\n\nDenklemin en buyuk derecesi : ");
			scanf("%d",&enbuyder);//Denklemin derecesi kullan�c�dan al�nd�
			for(i=enbuyder;i>=0;i--)
    		{
        		printf("\nx^%d.terimin katsayisi :",i);
        		scanf("%f",&pol[i]);
    		}//Denklemin katsay�lar� kullan�c�dan al�nd� ve pol dizisi i�erisinde tutuluyor
			printf("\nDenklem : ");
    		for(i=enbuyder;i>=0;i--)
    		{
        		printf(" %.3fx^%d",pol[i],i);
    		}
    		printf("\n\nAlt Sinir Degeri : ");
			scanf("%f",&a);//Alt s�n�r kullan�c�dan al�nd�
			printf("\nUst Sinir Degeri : ");
			scanf("%f",&b);//�st s�n�r kullan�c�dan al�nd�
			printf("\nEpsilon Degeri : ");
			scanf("%f",&epsilon);//Hata pay� kullan�c�dan al�nd�
			cik=1;
			printf("\n\n     A          F(A)           B           F(B)           C           F(C)\n");
			printf("--------------------------------------------------------------------------------");
			do{
				fa=0;//alt s�n�r�n fonksiyonda hesaplanm�� de�eri bu de�i�kende tutulacak
				fb=0;//�st s�n�r�n fonksiyonda hesaplanm�� de�eri bu de�i�kende tutulacak
				for (i=enbuyder;i>=0;i--)
				{
					fa+=pol[i]*(pow(a,i));//Alt s�n�r fonksiyonda yerine konularak hesaplan�yor
					fb+=pol[i]*(pow(b,i));//�st s�n�r fonksiyonda yerine konularak hesaplan�yor.
				}
				printf("\n %6.4f        %6.4f        %6.4f       %6.4f    ",a,fa,b,fb);//Ad�mlar ekrana yazd�r�l�yor
																					   //S�ras�yla a=ilk de�er,fa=fonksiyonda a'n�n yerine konulmu� hali
																					   //b=�st s�n�r de�eri, fb=fonksiyonda b'nin yerine konulmu� hali
				if (fa*fb<0)//f(a) ve f(b) nin �arp�m�n�n sonucunun negatif olup olmad��� kontrol ediliyor. E�er sonu� negatifse k�k vard�r
				{
					xc[k]=(b*fa-a*fb)/(fa-fb);//C de�eri hesaplan�yor. Form�l= -f(a)/c-a = f(b)/b-c
					for (i=enbuyder;i>=0;i--)
					{
						fc[k]+=pol[i]*(pow(xc[k],i));
					}//C de�eri fonksiyonda yerine konularak de�eri hesaplan�yor.
				}
				if (fa*fc[k]<0)//E�er �arp�mlar� negatifse
				{
					b=xc[k];//K�ke yakla�mak i�in �st s�n�r, bulunan c de�eri olarak ayarlan�yor.
				}
				else//Aksi durumda
				{
					a=xc[k];//Alt s�n�r k�ke yakla�t�r�l�yor
				}
				printf("  %6.4f        %6.4f",xc[k],fc[k]);//Ad�m ekrana yazd�r�l�yor
				if ((fabs(xc[k]-xc[k-1])<=epsilon)||(fabs(fc[k]-fc[k-1])<=epsilon))//E�er bulunun son iki de�erin fark� mutlak de�erce hata pay�ndan k���kse k�k bulunmu�tur.
				{
						cik=0;
					}
					k++;
				}while(cik==1);
				printf("\n\nDenklemin koku : %f", xc[k-1]);//K�k ekrana yazd�r�l�yor.
				printf("\n\nAna menuye donmek icin '0'a basiniz : ");
				scanf("%d",&menu);
				system("CLS");
				break;


		case 5://Matrisin inversinin al�nmas�
			system("CLS");
			printf("\n\n\t\t\t Matrisin Inversinin Alinmasi");
			printf("\n\n\nMatrisin Satir Sayisi :");
			scanf("%d",&satir);//Matrisin sat�r say�s� kullan�c�dan al�n�yor
			printf("\nMatrisin Sutun Sayisi :");
			scanf("%d",&sutun);//Matrisin stun say�s� kullan�c�dan al�n�yor
			printf("\n");
			for(i=0;i<satir;i++)
			{
				for(j=0;j<sutun;j++)
				{
					printf("Matrisin %d.satir %d.sutun elemanini giriniz :",i+1,j+1);
					scanf("%f",&matrisA[i][j]);
				}//Matrisin elemanlr� kullan�c�dan al�n�yor
			}
			printf("\n  MATRIS   \n");
			printf("---------------\n");
			for(i=0;i<satir;i++)//Kullan�c�dan al�nan matris ekrana yazd�r�l�yor.
			{
				for(j=0;j<sutun;j++)
				{
					printf("%6.3f  ",matrisA[i][j]);
				}
				printf("\n");
			}
			for(i=0;i<satir;i++)//B Matrisinde uygun boyutlarda birim matris olu�turuluyor
			{
				for(j=0;j<sutun;j++)
				{
					if(i==j)
					{
						matrisB[i][j]=1;
					}
					else
					{
						matrisB[i][j]=0;
					}
				}
			}
			
			
			
			
			for(i=0;i<satir;i++)
			{
				p=matrisA[i][i];//Matrisin diyagonelindeki eleman se�iliyor
				for(j=0;j<sutun;j++)
				{
					//B matrisinin diyagonelindeki de�erler �arpma i�leminin tersi olarak hesaplan�yor
					matrisA[i][j]=matrisA[i][j]/p;//
					matrisB[i][j]=matrisB[i][j]/p;
				}
				
				
				
				for(y=0;y<satir;y++)
				{
					if(y!=i)
					{
						r=matrisA[y][i];
						for(j=0;j<sutun;j++)
						{
							matrisA[y][j]=matrisA[y][j]-(matrisA[i][j]*r);
							matrisB[y][j]=matrisB[y][j]-(matrisB[i][j]*r);
						}
					}
				}
			}
			printf("\nMatrisin Tersi");
			printf("\n---------------\n");
			for(i=0;i<satir;i++)
			{
				for(j=0;j<sutun;j++)
				{
					printf("%6.3f  ",matrisB[i][j]);
				}
				printf("\n");
			}
			printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;
		case 6://Gauss eleminasyon y�ntemi
			system("CLS");
			printf("\n\n\t\t\t Gauss Eleminasyon Yontemi\n");
			printf("\n\n\nDenklemlerin Sayisi : ");
			scanf("%d",&n);
			printf("\n");
			for(i=1;i<=n;i++)
    		{
        		for(j=1;j<=n+1;j++)
        		{
        			if(j!=n+1)
        			{
						printf("%d.denklemin x%d katsayisi : ",i,j);
            			scanf("%f",&matrisA[i][j]);
        			}
        			else
        			{
        				printf("%d.denklemin sonucu : ",i);
            			scanf("%f",&matrisA[i][j]);
					}
				}
				printf("\n");
    		}
			printf("               Denklemler");
			printf("\n--------------------------------------------------\n");
			for(i=1;i<=n;i++)
			{
				printf("%d.denklem : ",i);
				for(j=1;j<=n+1;j++)
				{
					if(j==n+1)
					{
						printf("= %6.3f  ",matrisA[i][j]);
					}
					else
					{
						printf("%6.3fx%d ",matrisA[i][j],j);
					}
				}
				printf("\n");
			}
			for(j=1; j<=n; j++)
    		{
        		for(i=1; i<=n; i++)
        		{
            		if(i>j)
            		{
                		c=matrisA[i][j]/matrisA[j][j];
                		for(k=1; k<=n+1; k++)
                		{
                    		matrisA[i][k]-=c*matrisA[j][k];
               			}
            		}
        		}
    		}
    		x[n]=matrisA[n][n+1]/matrisA[n][n];
    		for(i=n-1; i>=1; i--)
    		{
        		sayim=0;
        		for(j=i+1; j<=n; j++)
        		{
            		sayim+=matrisA[i][j]*x[j];
       	 		}
        		x[i]=(matrisA[i][n+1]-sayim)/matrisA[i][i];
    		}
   			printf("\nBulunan Degerler: \n");
    		for(i=1;i<=n;i++)
    		{
        		printf("\nx%d=%f\t",i,x[i]);
			}
        	printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;
		case 7://Trapez y�ntemi
			    X0=0;
				Xn=0;
				n=0;
				system("CLS");
				printf("\n\n\t\t\t Trapez Yontemi\n");
				printf("\n\n\nDenklemin en buyuk derecesi : ");
				scanf("%d",&enbuyder);
				for(i=enbuyder;i>=0;i--)
    			{
        			printf("\nx^%d.terimin katsayisi :",i);
        			scanf("%f",&pol[i]);
    			}
				printf("\nDenklem : ");
    			for(i=enbuyder;i>=0;i--)
    			{
        			printf(" %.3fx^%d",pol[i],i);
    			}
				printf("\n\nx0 baslangic degeri : ");
				scanf("%f",&X0);
				printf("\nXn degeri : ");
				scanf("%f",&Xn);
				printf("\nKac esit parcaya boleceksiniz : ");
				scanf("%d",&n);
				h=(Xn-X0)/n;
				printf("\nh degeri =>> (%0.0f-%0.0f)/%d = %0.2f ",Xn,X0,n,h);
				printf("\n\nX degerleri    f(x) degerleri \n");
				printf("------------------------------");
				for(i=0;i<n;i++)
				{
					if(i==0)
					{
						x0[0]=X0;
					}
					else
					{
						x0[i]=x0[i-1]+h;
					}
				}
    			for(i=0; i<=n; i++)
    			{
        			x0[i]=X0+i*h;
        			for(k=0;k<=enbuyder;k++)
        			{
						fX02[i]+=pol[k] * (pow(x0[i],k)) ;
					}
					printf("\n   %0.2f     => %0.4f\n",x0[i],fX02[i]);
				}
				for(i=1;i<n;i++)
				{
					toplam+=fX02[i];
				}
				cevap=h*((fX02[0]+fX02[n])/2+toplam);
                printf("\n Belirli integralinin sonucu : %0.5f",cevap);
				printf("\n\nAna menuye donmek icin '0'a basiniz : ");
				scanf("%d",&menu);
				system("CLS");
				break;
		case 8://Simpson y�ntemi
				X0=0;
				Xn=0;
				n=0;
				system("CLS");
				printf("\n\n\t\t\t Simpson Yontemi\n");
				printf("\n\n\nDenklemin en buyuk derecesi : ");
				scanf("%d",&enbuyder);
				for(i=enbuyder;i>=0;i--)
    			{
        			printf("\nx^%d.terimin katsayisi :",i);
        			scanf("%f",&pol[i]);
    			}
				printf("\nDenklem : ");
    			for(i=enbuyder;i>=0;i--)
    			{
        			printf(" %.3fx^%d",pol[i],i);
    			}
				printf("\n\nx0 baslangic degeri : ");
				scanf("%f",&X0);
				printf("\nXn degeri : ");
				scanf("%f",&Xn);
				printf("\nKac esit parcaya boleceksiniz : ");
				scanf("%d",&n);
				h=(Xn-X0)/n;
				printf("\nh degeri =>> (%0.0f-%0.0f)/%d = %0.2f ",Xn,X0,n,h);
				printf("\n\nX degerleri    f(x) degerleri \n");
				printf("------------------------------");
				for(i=0;i<n;i++)
				{
					if(i==0)
					{
						x0[0]=X0;
					}
					else
					{
						x0[i]=x0[i-1]+h;
					}
				}
    			for(i=0; i<=n; i++)
    			{
        			x0[i]=X0+i*h;
        			for(k=0;k<=enbuyder;k++)
        			{
						fX01[i]+=pol[k] * (pow(x0[i],k)) ;
					}
					printf("\n   %0.2f     => %0.4f\n",x0[i],fX01[i]);
				}
    			for(i=0;i<n-1;i++)
    			{
        			if((i+1)%2==1)
        			{
			            tek+=fX01[i+1];
			        }
			        else
			        {
			            cift+=fX01[i+1];
			        }
			    }
			    cevap=h/3*((fX01[0]+fX01[n]+4*tek+2*cift));
				printf("\n Belirli integralinin sonucu : %0.5f",cevap);
				printf("\n\nAna menuye donmek icin '0'a basiniz : ");
				scanf("%d",&menu);
				system("CLS");
				break;
		case 9://N�merik t�rev y�ntemi
			system("CLS");
			printf("\n\n\t\t\t Numerik Turev");
			printf("\n\n\nDenklemin en buyuk derecesi : ");
			scanf("%d",&enbuyder);
			for(i=enbuyder;i>=0;i--)
    		{
        		printf("\nx^%d.terimin katsayisi :",i);
        		scanf("%f",&pol[i]);
    		}
			printf("\nDenklem : ");
    		for(i=enbuyder;i>=0;i--)
    		{
        		printf(" %.3fx^%d",pol[i],i);
    		}
			printf("\n\nX icin baslangic degerini giriniz : ");
			scanf("%f",&x1);
			printf("\nDelta degerini giriniz : ");
			scanf("%f",&delta);
			X0=x1-delta;
			x2=x1+delta;
			for(i=enbuyder;i>=1;i--)
		    {
		        fx1+=pol[i] * (pow(x1,i)) ;
		    }
			for(i=enbuyder;i>=1;i--)
		    {
		        fx0+=pol[i] * (pow(X0,i)) ;
		    }
		    for(i=enbuyder;i>=1;i--)
		    {
		        fx2+=pol[i] * (pow(x2,i)) ;
		    }
		    ileri=(float)(fx2-fx1)/delta;
			geri=(float)(fx1-fx0)/delta;
		    merkezi=(float)(ileri+geri)/2;
		    printf("\n�leri Fark ile Turev   : %f",ileri);
			printf("\nGeri Fark ile Turev    : %f",geri);
		    printf("\nMerkezi Fark ile Turev : %f",merkezi);
			printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;
		case 10://Program�n sonlanmas�
			system("CLS");
			return 0;
			break;
		}
	}
	return 0;
}
