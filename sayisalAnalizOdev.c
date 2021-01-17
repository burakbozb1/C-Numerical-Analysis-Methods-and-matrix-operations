/* Sayýsal Analiz

Burak Boz

Yöntemler ve giriþ kodlarý
1 -> Yarýya bölme yöntemi +
2 -> Grafik yöntemi +
3 -> Newton Raphson yöntemi +
4 -> Regula false yöntemi +
5 -> Matrisin inversi
6 -> Gauss eleminasyon yöntemi
7 -> Trapez yöntemi
8 -> Simpson yöntemi
9 -> Nümerik türev

10 -> Programdan çýkýþ


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
			case 1://Yarýya Bölme yöntemi
			system("CLS");
			printf("\n\n\t\t\t Yariya Bolme Yontemi");
			printf("\n\n\nDenklemin en buyuk derecesi : ");//Denklemin derecesi kullanýcýdan isteniyor
			scanf("%d",&enbuyder);//En büyük deðer okunuyor
			for(i=enbuyder;i>=0;i--)//Katsayýlar Kullanýcýdan isteniyor
    		{
        		printf("\nx^%d.terimin katsayisi :",i);
        		scanf("%f",&pol[i]);//Katsayýlar dizinin içerisine aktarýlýyor
    		}
			printf("\nDenklem : ");
    		for(i=enbuyder;i>=0;i--)//Kullanýcýnýn girdiði denklem ekrana yazdýrýlýyor
    		{
        		printf(" %.3fx^%d",pol[i],i);
    		}
    		printf("\n\nAlt Sinir Degeri : ");//Alt sýnýr deðeri kullanýcýndan isteniyor ve a deðiþkeni içerisine atýlýyor
			scanf("%f",&a);
			printf("\nUst Sinir Degeri : ");//Üst sýnýr deðeri kullanýcýdan isteniyor ve b deðiþkeni içerisine atýlýyor
			scanf("%f",&b);
			printf("\nEpsilon Degeri : ");//Hata payý kullanýcýdan isteniyor ve epsilon deðiþkeninin içine atýlýyor
			scanf("%f",&epsilon);
			cik=1;
			printf("\n\n     A          F(A)           B           F(B)            C           F(C)\n");
			printf("--------------------------------------------------------------------------------");
			do{
				fa=0;
				fb=0;
				for (i=enbuyder;i>=0;i--)//Alt sýnýr ve üst sýnýr deðerlerinin hesaplanmasý ve f(a) ve f(b) deðiþkenleri içerisine eklenmesi
				{
					fa+=pol[i]*(pow(a,i));
					fb+=pol[i]*(pow(b,i));
				}
				printf("\n %6.4f        %6.4f        %6.4f       %6.4f    ",a,fa,b,fb);//Hesaplanan deðerlerin fonksiyona girilen deðerler ile birlikte ekrana yazdýrýlmasý
				if (fa*fb<0)//Eðer fonksiyon çýktýlarýnýn çarpýmlarý negatifse a ve b aralýðýnda kök vardýr ve ortalama hesaplanýr
				{
					xc[k]=(a+b)/2;//Ortalama xC dizisi içinde tutulacak
					for (i=enbuyder;i>=0;i--)
					{
						fc[k]+=pol[i]*(pow(xc[k],i));//pow üs almak için
					}
				}
				if (fa*fc[k]<0)//Eðer çarpýmlar negatifse büyük deðeri ortalama olarak güncelliyoruz
				{
					b=xc[k];
				}
				else//Deðilse küçük deðeri ortalama olarak güncelliyoruz
				{
					a=xc[k];
				}
				printf("     %6.4f       %6.4f",xc[k],fc[k]);//Ýterasyondan çýkan deðeri ekrana yazdýrýyoruz
				if ((fabs(xc[k]-xc[k-1])<=epsilon)||(fabs(fc[k]-fc[k-1])<=epsilon))//Ortalamalar arasýndaki fark mutlak deðerce hata payýndan küçükse döngüden çýkýyoruz
				{
					cik=0;
				}
			  k++;
		   }while(cik==1);//cik deðeri 0 ise döngüden çýkýlacak
			printf("\n\nDenklemin koku : %f", xc[k-1]);//Kök ekrana yazýlýyor
			printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;

		case 2://Grafik yöntemi
		    system("CLS");
				printf("\n\n\t\t\t Grafik Yontemi");
				printf("\n\n\nDenklemin en buyuk derecesi : ");
				scanf("%d",&enbuyder);//Kullanýcýdan denklemin derecesi isteniyor.
				for(i=enbuyder;i>=0;i--)//Denklemin oluþturulabilmesi için kullanýcýdan katsayýlar alýnýyor.
    			{
        			printf("\nx^%d.terimin katsayisi :",i);
        			scanf("%f",&pol[i]);//Katsayýlar pol dizisi içerisinde tutulacak
    			}
				printf("\nDenklem : ");//Oluþturulan denklem ekrana yazýlýyor.
    			for(i=enbuyder;i>=0;i--)
    			{
        			printf(" %.3fx^%d",pol[i],i);
    			}
				printf("\n\nX0 baslangic degeri : ");//Baþlangýç deðeri kullanýcýdan alýnýyor
    			scanf("%f",&x0);
    			printf("\nDelta x degeri :");//deltaX deðeri kullanýcýdan alýnýyor
    			scanf("%f",&delta);
    			printf("\nEpsilon degeri :");//Hata payý kullanýcýdan alýnýyor.
    			scanf("%f",&epsilon);
    			t=0;//T deðiþkeni kökün bulunmasýnda index olarak kullanýlacak
    			bitir=1;//While'ýn sonuçlandýrýlmasý için bool deðer olarak kullanýlýyor
    			sayac=1;//Ýterasyon sayýsý sayaç içerisinde tutulacak
    			//Gerekli fonksiyonun ve deðerlerin kullanýcýdan alýnmasý tamamlandý
   				do
    			{
			   	    devam=0;
			        printf("\n\n       %d. Iterasyon\n",sayac);
					printf("     X              F(x)\n");
					printf("---------------------------");//Bu bölümde iterasyon sayýsý ekrana yazdýrýlýyor.
					while(devam!=1)//Hesaplamalar bu while içerisinde yapýlýyor.
					{
			            for(i=enbuyder;i>=0;i--)//Deðer  fonksiyon içerisine konularak f(x) þeklinde hesaplanýyor.
			            {
			                fX0[t]+=pol[i] * (pow(x0[t],i)) ;
			            }
			            printf("\n%10.6f",x0[t]);
						printf("	%10.6f",fX0[t]);
						bolum=fX0[t]/fabs(fX0[t]);//Ýþaretin deðiþip deðiþmediðini kontrol etmek için kendine bölüyoruz
						x0[t+1]=x0[t]+delta;//x0 Deðerinin bir sonraki deðerini hesaplamak için üzerinde delta deðeri ekleniyor
						if (sonuc==0)//Sonuç deðeri baþlangýçta 0 olarak ilklendirildi. Bu kod sadece ilk adýmda çalýþacak
						{
							sonuc=bolum;
						}
						if(sonuc!=bolum)//Sonuç eðer bölüm deðerine eþit deðilse þartlarý kontrol edeceðiz. Bu kod ilk adýmda çalýþmayýp ikinci adýmda çalýþmasý için yazýldý
						{
							if ((fabs(fX0[t]-fX0[t-1])<=epsilon)||(delta<=epsilon))//Bulunan deðer ve bir önceki deðerin farký hata payýndan mutlak deðerce küçükse
						    {													   //ya da deltaX deðeri hata payýdan küçükse dögüden çýkýlýyor.
							  bitir=0;	//Þartlar saðlandýysa kök bulunmuþtur
						    }
						    devam=1;
							x0[t+1]=x0[t]-delta;	//x0ýn bir sonraki deðeri hesaplanýyor
							delta/=2;
						}
						t++;
				   }
				   sayac++;
			}while(bitir==1);
			
			printf("\n");
			printf("\nKok => %f", x0[t-1]);//t deðeri kökten bir sonraki deðeri index'lediði için bir önceki deðer bizim bulduðumuz kök deðeridir.
			printf("\n--------------------------");
			printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;

		case 3://Newton Raphson yöntemi
			  		    system("CLS");
			printf("\n\n\t\t\t Newton Raphson Yontemi");
			printf("\n\n\nDenklemin en buyuk derecesi : ");
			scanf("%d",&enbuyder);//Kullanýcýdan denklemin derecesi alýndý
			for(i=enbuyder;i>=0;i--)//Bu for içerisinde denklemin katsayýlarý kullanýcýdan alýndý ve pol dizisi içerisinde tutuluyor.
    		{
        		printf("\nx^%d.terimin katsayisi :",i);
        		scanf("%f",&pol[i]);
    		}
			printf("\nDenklem : ");//Alýnan denklem ekrana yazdýrýldý.
    		for(i=enbuyder;i>=0;i--)
    		{
        		printf(" %.3fx^%d",pol[i],i);
    		}
			printf("\n\nX0 baslangic degeri : ");
		    scanf("%f",&X0);//Baþlangýç deðeri kullanýcýdan alýndý
		    printf("\nEpsilon degeri :");
		    scanf("%f",&epsilon);//Hata payý kullanýcýdan alýndý
			printf("\n Iterasyon    X0         X1  ");
		    printf("\n ------------------------------");
			k=0;
			do
		    {
		            k++;//Ýterasyon sayýsý k deðiþkeni içerisinde tutuluyor.
		            fx0=fdx0=0;//X deðeri fonksiyona konacak ve fx0 deðiþkeni içerisinde tutulacak, Türev deðeri ise fdx0 deðiþkeni içerisinde tutulacak
		            for(i=enbuyder;i>=1;i--)
		            {
		                fx0+=pol[i] * (pow(X0,i)) ;//x deðeri fonksiyonda yerine konularak hesaplanýyor.
		            }
		            fx0+=pol[0];
		            for(i=enbuyder;i>=0;i--)
		            {
		                fdx0+=pol[i]* (i*pow(X0,(i-1)));//fonksiyonun türevi alýnarak x deðeri fonksiyonda yerine konuluyor ve fdx0 deðeri hesaplanýyor
		            }
		            m=x1;//x1 deðeri geçici olarak m deðiþkeni içerisinde saklanýyor.
		            x1=(X0-(fx0/fdx0));//Bir sonraki deðer hesaplanýyor
		            printf("\n %d         %.6f  %.6f ",k,X0,x1);//sýrasýyla iterasyon,x0,x1 deðerleri ekrana yazdýrýldý
		            X0=x1;
			}while((fabs(m - X0))>=epsilon);//Eðer önceki adýmda bulunan x1 deðeri(yani m) x0 deðerinden çýkarlýlýyor ve mutlak deðerce epsilon deðerinden büyük
											// olup olmadýðý kontrol ediliyor. Eðer epsilon deðerinden büyükse adýmlar tekrarlanýyor. Küçükse kök bulunmuþtur.
		    printf("\n\nDenklemin Koku : %f",x1);//Bulunan sonuç ekrana yazdýrýlýyor.
		    printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;

		case 4://Regula False yöntemi
		    system("CLS");
			printf("\n\n\t\t\t Regula False Yontemi");
			printf("\n\n\nDenklemin en buyuk derecesi : ");
			scanf("%d",&enbuyder);//Denklemin derecesi kullanýcýdan alýndý
			for(i=enbuyder;i>=0;i--)
    		{
        		printf("\nx^%d.terimin katsayisi :",i);
        		scanf("%f",&pol[i]);
    		}//Denklemin katsayýlarý kullanýcýdan alýndý ve pol dizisi içerisinde tutuluyor
			printf("\nDenklem : ");
    		for(i=enbuyder;i>=0;i--)
    		{
        		printf(" %.3fx^%d",pol[i],i);
    		}
    		printf("\n\nAlt Sinir Degeri : ");
			scanf("%f",&a);//Alt sýnýr kullanýcýdan alýndý
			printf("\nUst Sinir Degeri : ");
			scanf("%f",&b);//Üst sýnýr kullanýcýdan alýndý
			printf("\nEpsilon Degeri : ");
			scanf("%f",&epsilon);//Hata payý kullanýcýdan alýndý
			cik=1;
			printf("\n\n     A          F(A)           B           F(B)           C           F(C)\n");
			printf("--------------------------------------------------------------------------------");
			do{
				fa=0;//alt sýnýrýn fonksiyonda hesaplanmýþ deðeri bu deðiþkende tutulacak
				fb=0;//üst sýnýrýn fonksiyonda hesaplanmýþ deðeri bu deðiþkende tutulacak
				for (i=enbuyder;i>=0;i--)
				{
					fa+=pol[i]*(pow(a,i));//Alt sýnýr fonksiyonda yerine konularak hesaplanýyor
					fb+=pol[i]*(pow(b,i));//Üst sýnýr fonksiyonda yerine konularak hesaplanýyor.
				}
				printf("\n %6.4f        %6.4f        %6.4f       %6.4f    ",a,fa,b,fb);//Adýmlar ekrana yazdýrýlýyor
																					   //Sýrasýyla a=ilk deðer,fa=fonksiyonda a'nýn yerine konulmuþ hali
																					   //b=üst sýnýr deðeri, fb=fonksiyonda b'nin yerine konulmuþ hali
				if (fa*fb<0)//f(a) ve f(b) nin çarpýmýnýn sonucunun negatif olup olmadýðý kontrol ediliyor. Eðer sonuç negatifse kök vardýr
				{
					xc[k]=(b*fa-a*fb)/(fa-fb);//C deðeri hesaplanýyor. Formül= -f(a)/c-a = f(b)/b-c
					for (i=enbuyder;i>=0;i--)
					{
						fc[k]+=pol[i]*(pow(xc[k],i));
					}//C deðeri fonksiyonda yerine konularak deðeri hesaplanýyor.
				}
				if (fa*fc[k]<0)//Eðer çarpýmlarý negatifse
				{
					b=xc[k];//Köke yaklaþmak için üst sýnýr, bulunan c deðeri olarak ayarlanýyor.
				}
				else//Aksi durumda
				{
					a=xc[k];//Alt sýnýr köke yaklaþtýrýlýyor
				}
				printf("  %6.4f        %6.4f",xc[k],fc[k]);//Adým ekrana yazdýrýlýyor
				if ((fabs(xc[k]-xc[k-1])<=epsilon)||(fabs(fc[k]-fc[k-1])<=epsilon))//Eðer bulunun son iki deðerin farký mutlak deðerce hata payýndan küçükse kök bulunmuþtur.
				{
						cik=0;
					}
					k++;
				}while(cik==1);
				printf("\n\nDenklemin koku : %f", xc[k-1]);//Kök ekrana yazdýrýlýyor.
				printf("\n\nAna menuye donmek icin '0'a basiniz : ");
				scanf("%d",&menu);
				system("CLS");
				break;


		case 5://Matrisin inversinin alýnmasý
			system("CLS");
			printf("\n\n\t\t\t Matrisin Inversinin Alinmasi");
			printf("\n\n\nMatrisin Satir Sayisi :");
			scanf("%d",&satir);//Matrisin satýr sayýsý kullanýcýdan alýnýyor
			printf("\nMatrisin Sutun Sayisi :");
			scanf("%d",&sutun);//Matrisin stun sayýsý kullanýcýdan alýnýyor
			printf("\n");
			for(i=0;i<satir;i++)
			{
				for(j=0;j<sutun;j++)
				{
					printf("Matrisin %d.satir %d.sutun elemanini giriniz :",i+1,j+1);
					scanf("%f",&matrisA[i][j]);
				}//Matrisin elemanlrý kullanýcýdan alýnýyor
			}
			printf("\n  MATRIS   \n");
			printf("---------------\n");
			for(i=0;i<satir;i++)//Kullanýcýdan alýnan matris ekrana yazdýrýlýyor.
			{
				for(j=0;j<sutun;j++)
				{
					printf("%6.3f  ",matrisA[i][j]);
				}
				printf("\n");
			}
			for(i=0;i<satir;i++)//B Matrisinde uygun boyutlarda birim matris oluþturuluyor
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
				p=matrisA[i][i];//Matrisin diyagonelindeki eleman seçiliyor
				for(j=0;j<sutun;j++)
				{
					//B matrisinin diyagonelindeki deðerler çarpma iþleminin tersi olarak hesaplanýyor
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
		case 6://Gauss eleminasyon yöntemi
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
		case 7://Trapez yöntemi
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
		case 8://Simpson yöntemi
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
		case 9://Nümerik türev yöntemi
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
		    printf("\nÝleri Fark ile Turev   : %f",ileri);
			printf("\nGeri Fark ile Turev    : %f",geri);
		    printf("\nMerkezi Fark ile Turev : %f",merkezi);
			printf("\n\nAna menuye donmek icin '0'a basiniz : ");
			scanf("%d",&menu);
			system("CLS");
			break;
		case 10://Programýn sonlanmasý
			system("CLS");
			return 0;
			break;
		}
	}
	return 0;
}
