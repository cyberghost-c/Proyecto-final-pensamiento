#include<iostream>
#include<string.h>
using namespace std;
void captura(); //Captura tipo de usuario
void terapeuta(string x[], int especialidad); //Interfaz de terapeuta
void paciente(); //Interfaz de pacientevoid ejecucion_ejercicio(int pos, int especialidad); //Interfaz para que el paciente responda si ya realizo la terapia y las obsevaciones de la misma
void tratamiento(int id_paciente, int especialidad_terapeuta); //Interfaz para asignaci�n de terapias
void usuarios_sistema(); //Ciclo Do While para aumentar contador de la lista a[X]
void feed_back(int numero, int especialidad); //El paciente introducir� observaciones sobre su tratamiento
string a[500], end="\n"; 
string feedback[500];
int especialidad, cont;
int main()
{
    //Inicio del programa
    cout<<"--------Sistema de fisioterapia online--------"<<endl;
    usuarios_sistema();
}
//Funcion para identificar tipo de usuario, ejecuta sus funciones respectivas segun la decision
void captura() 
{
    int selec, espCil;
    cout<<"Seleccione su tipo de usuario: "<<endl<<"1. Terapeuta"<<endl<<"2. Paciente"<<endl;
    cin>>selec;
    if(selec==1&&cont==0)
    {
       cout<<"No hay pacientes en el sistema, revise mas tarde"<<endl; 
    }
    else if(selec==2)
    {
    	paciente();
    }
    else if(selec==1&&cont!=0)
    {
    	cout<<"Digite su ID unico (1-5)"<<endl;
    	cin>>espCil;
        terapeuta(a, espCil);
	}
    
}
// funcion para saber si hay mas usuarios en el sistema 
void usuarios_sistema()
{
    char respuesta;
    do
    {
        captura();
        cout<<"Hay mas usuarios en el sistema, en esta semana? (s/n)"<<endl;
        cin>>respuesta;
        cont=cont+1; //Aumenta contador para llenar la lista 
    } 
    while (respuesta=='s');
}
//funcion interfaz paciente 
void paciente() 
{
    int rta, rta2;
    char rta3, rta4;
    cout<<endl;
    cout<<"-----Bienvenido a la interfaz de usuario-----"<<endl;
    cout<<endl;
    cout<<"Es usted un paciente nuevo? "<<endl<<"1. Si"<<endl<<"2. No"<<endl;
    cin>>rta; cout<<endl;
    if(rta==1)
    {
        cout<<"Escriba su historia clinica: (Usando '_' como espacios) Mil gracias."<<endl;
        cin>>a[cont];
        cout<<"Su ID unico es el: "<<cont<<endl;
        cout<<"Que especialista quiere ver: "<<endl<<" 1.Ortopedica "<<endl<<" 2.Traumatologica "<<endl<<" 3.Deportiva "<<endl<<" 4.Geriatrica "<<endl<<" 5.Neurologica "<<endl;
        cin>>especialidad;
        if(especialidad>0&&especialidad<6)
        {
          terapeuta(a,especialidad);  
        }
        else
        {
            do
            {
                cout<<"Lo lamentamos, pero de momento no contamos con la especialidad seleccionada."<<endl;
                cout<<"Que especialista quiere ver: "<<endl<<" 1.Ortopedica "<<endl<<" 2.Traumatologica "<<endl<<" 3.Deportiva "<<endl<<" 4.Geriatrica "<<endl<<" 5.Neurologica "<<endl;
                cin>>especialidad;
            } while (especialidad>6);
            terapeuta(a, especialidad);
        }
        
    }
    else
    {
        cout<<"Digite su numero de paciente: "<<endl;
        cin>>rta2;
        cout<<a[rta2]<<endl<<" Es esta informacion correcta? (s/n)"<<endl;
        cin>>rta3;
        if(rta3=='s')
        {
        	cout<<"Que especialista quiere ver: "<<endl<<" 1.Ortopedica "<<endl<<" 2.Traumatologica "<<endl<<" 3.Deportiva "<<endl<<" 4.Geriatrica "<<endl<<" 5.Neurologica "<<endl;
            cin>>especialidad;
            cout<<"Quiere volver a ser evaluado?(s/n)"<<endl;
            cin>>rta4;
        	if(rta4=='s')
            {
               terapeuta(a,especialidad); 
            }
            else
            {
               ejecucion_ejercicio(rta2,especialidad); 
            }
            
        }
        else
        {
            cout<<"Digite su numero de paciente de nuevo: "<<endl;
            cin>>rta2;
            cout<<a[rta2]<<endl;
            cout<<"Que especialista quiere ver: "<<endl<<" 1.Ortopedica "<<endl<<" 2.Traumatologica "<<endl<<" 3.Deportiva "<<endl<<" 4.Geriatrica "<<endl<<" 5.Neurologica "<<endl;
            cin>>especialidad;
            cout<<"Quiere volver a ser evaluado?"<<endl;
            cin>>rta4;
        	if(rta4=='s')
            {
               terapeuta(a,especialidad); 
            }
            else
            {
               ejecucion_ejercicio(rta2,especialidad); 
            }
            
        }
    }   
}
//Interfaz para que el paciente responda si ya realizo la terapia y las obsevaciones de la misma
void ejecucion_ejercicio(int n_paciente, int especialidad)
{
    char resp;
    string alfa, beta ;
    cout<<"Desea ver su historial clinico?(s/n)"<<endl;
    cin>>resp; cout<<endl;
    if(resp=='s')
    {
        cout<<"Los ejercicios a realizar para la siguiente consulta son"<<"\n"<<a[n_paciente]<<endl;
        cout<<"Ya realizo los ejercicios propuestos?(s/n)"<<endl;
        cin>>resp;
        if(resp=='s')
        {
        	cout<<"Las observaciones hechas se mostraran a continuacion:"<<endl;
            cout<<feedback[n_paciente]<<endl;
            cout<<"Escriba sus observaciones con relacion a la terapia enviada: "<<endl;
            cin>>alfa; cout<<endl;
            cout<<"Escriba en una escala del 1 al 5 el dolor presentado"<<endl;
            cin>>beta; cout<<endl;
            alfa=alfa+" El nivel de dolor fue: "+beta+end;
            feedback[n_paciente]=feedback[n_paciente]+alfa+end; 
            feed_back(n_paciente, especialidad); //Feedback hace parte de la interfaz de Terapeuta
        }
        else
        {
            cout<<"Las observaciones hechas se mostraran a continuacion:"<<endl;
            cout<<feedback[n_paciente]<<endl;

        }
    }
    else
    {
        cout<<"Ya realizo los ejercicios propuestos?(s/n)"<<endl;
        cin>>resp;
        if(resp=='s')
        {
            cout<<"Las observaciones hechas se mostraran a continuacion:"<<endl;
            cout<<feedback[n_paciente]<<endl;
            cout<<"Escriba sus observaciones con relacion a la terapia enviada: "<<endl;
            cin>>alfa; cout<<endl;
            cout<<"Escriba en una escala del 1 al 5 el dolor presentado"<<endl;
            cin>>beta; cout<<endl;
            alfa=alfa+" El nivel de dolor fue: "+beta+end;
            feedback[n_paciente]=feedback[n_paciente]+alfa+end; 
            feed_back(n_paciente, especialidad); //Feedback hace parte de la interfaz de Terapeuta
        }
        else
        {
        	cout<<"Las observaciones hechas  se mostraran a continuacion:"<<endl;
            cout<<feedback[n_paciente]<<endl;
            cout<<"Fin del ciclo."<<endl;
            paciente();
		}
    }
} 
void feed_back( int n_paciente, int especialidad)
{
    char rta, rta2;
    string Obser, beta;
    cout<<"----Interfaz de terapeuta----"<<endl;
    cout<<"El paciente identificado con el ID "<<n_paciente<<" ha dejado la siguiente observacion: "<<endl;
    cout<<feedback[n_paciente]<<endl;
    cout<<"Desea agregar alguna Valoracion?(s/n)"<<endl;
    cin>>rta2;
    if(rta2=='s')
    {
        cout<<"Digite la observacion a continuacion: "<<endl; 
        cout<<"No olvide evaluar lo siguiente dentro de sus observaciones: (porcentaje de: fuerza, movilidad y flexibilidad)  "<<endl;
        cin>>Obser;
        cout<<"En una escala del 1 al 5, la mejoria del paciente con respecto al principio fue: "<<endl;
        cin>>beta;
        Obser=Obser+" El nivel mejoria fue:"+beta+end;
        feedback[n_paciente]=feedback[n_paciente]+"Valoracion del Terapeuta: "+Obser+ end;
        cout<<"Desea editar las terapias proporcionadas a este paciente?(s/n)"<<endl;
        cin>>rta;
        if(rta=='s')
        {
            tratamiento(n_paciente, especialidad);
        }
        else
        {
            paciente();
        } 
    }
    else
    {
       cout<<"Desea editar las terapias proporcionadas a este paciente?(s/n)"<<endl;
        cin>>rta;
        if(rta=='s')
        {
            tratamiento(n_paciente, especialidad);
        } 
        else
        {
            paciente();
        }
    }
    
}
//Funcion con interfaz del terapeuta 
void terapeuta(string historias[], int area)
{
    int rt,id_terapeuta;
    char ita;
    cout<<endl;
    cout<<"Interfaz de terapeuta"<<endl;
    cout<<"-------Bienvenido-------"<<endl;
    cout<<endl;
    cout<<"Digite su ID unico de terapeuta"<<endl;
    cin>>id_terapeuta;
    if(area==1) //Guarda la selecci?n de especialidad y las compara
    {
        cout<<" ";
        if(id_terapeuta==1)
        {
            cout<<endl<<"Digite el ID unico del usuario a revisar"<<endl;
            cin>>rt;
            cout<<"La historia clinica del paciente seleccionado es la siguiente:"<<endl;
             cout<<historias[rt]<<endl;
             cout<<"Desea asignar terapias?(s/n)"<<endl;
             cin>>ita;
            if(ita=='s')
            {
                tratamiento(rt, area); //Activa la funci?n de asignaci?n usando como parametro la pos y especialidad.
            }
            else
            {
                cout<<"Desea hacerle valoraciones al paciente?(s/n)"<<endl;
                cin>>ita;
                if(ita=='s')
                {
                	feed_back(rt, id_terapeuta);
				}
                else
                {
                    usuarios_sistema();
                }
            }
        }
        else
        {
            cout<<"Aun no hay pacientes por atender. "<<endl;
        }
    }
    else if(area==2)
    {
        cout<<"Traumatologia ";
        if(id_terapeuta==2)
        {
            cout<<"Digite el ID unico del usuario a revisar"<<endl;
            cin>>rt;
            cout<<"La historia clinica del paciente seleccionado es la siguiente:"<<endl;
             cout<<historias[rt]<<endl;
             cout<<"Desea asignar terapias?(s/n)"<<endl;
             cin>>ita;
             if(ita=='s')
            {
                tratamiento(rt, area);
            }
            else
            {
                paciente();
            }
        }
        else
        {
            cout<<"Aun no hay pacientes por atender. "<<endl;
        }
    }
    else if(area==3)
    {
        cout<<"Deportiva ";
        if(id_terapeuta==3)
        {
            cout<<"Digite el ID unico del usuario a revisar"<<endl;
            cin>>rt;
            cout<<"La historia clinica del paciente seleccionado es la siguiente:"<<endl;
             cout<<historias[rt]<<endl;
             cout<<"Desea asignar terapias?(s/n)"<<endl;
             cin>>ita;
             if(ita=='s')
            {
                tratamiento(rt, area);
            }
            else
            {
                paciente();
            }
        }
        else
        {
            cout<<"Aun no hay pacientes por atender. "<<endl;
        }
    }
    else if(area==4)
    {
        cout<<"Geriatrica ";
        if(id_terapeuta==4)
        {
            cout<<"Digite el ID unico del usuario a revisar"<<endl;
            cin>>rt;
            cout<<"La historia clinica del paciente seleccionado es la siguiente:"<<endl;
             cout<<historias[rt]<<endl;
             cout<<"Desea asignar terapias?(s/n)"<<endl;
             cin>>ita;
             if(ita=='s')
            {
                tratamiento(rt, area);
            }
            else
            {
                paciente();
            }
        }
        else
        {
            cout<<"Aun no hay pacientes por atender. "<<endl;
        }
    }
    else if(area==5)
    {
        cout<<"Neurologia ";
        if(id_terapeuta==5)
        {
            cout<<"Digite el ID unico del usuario a revisar"<<endl;
            cin>>rt;
            cout<<"La historia clinica del paciente seleccionado es la siguiente:"<<endl;
             cout<<historias[rt]<<endl;
             cout<<"Desea asignar terapias?(s/n)"<<endl;
             cin>>ita;
             if(ita=='s')
            {
                tratamiento(rt, area);
            }
            else
            {
                paciente();
            }
        }
        else
        {
            cout<<"Aun no hay pacientes por atender. "<<endl;
        }
    }
    
}
void tratamiento(int id_unico, int especialidad)
{
    string z,b,c,d,e, terapia=" ", tera1="0", tera2="0", tera3="0", tera4="0", tera5="0";
    char respuesta;
    int rta; 
    cout<<"<-----Bienvenido a la interfaz para la asignacion de terapias---->"<<endl;
    cout<<"El id del paciente seleccionado ha sido: "<<id_unico<<" cuyo historial clinico es el siguiente: "<<endl<<a[id_unico]<<endl<<"Terapeuta, recuerde que su especialidad es: "<<endl;
    if(especialidad==1) //Comparador para determinar el tipo de especialidad seleccionado en la funcion de paciente
    {
        cout<<" -Ortopedia- "<<endl;
    }
    else if(especialidad==2)
    {
        cout<<" -Traumatologia- "<<endl;
    }
    else if(especialidad==3)
    {
        cout<<" -Deportiva- "<<endl;
    }
    else if(especialidad==4)
    {
        cout<<" -Geriatrica- "<<endl;
    }
    else if(especialidad==5)
    {
        cout<<" -Neurologia- "<<endl;
    }
    cout<<" Es hora de asignar terapias, a continuacion se mostrara un menu de acuerdo a su especialidad"<<endl;
    switch (especialidad) //Switch dependiendo de la especialidad para asignaci?n 
    {
    case 1:
        
        z=" 1.Equilibrio en una pierna mientras toca el piso * repeticiones: "+tera1;
        b=" 2.Rotacion interna de hombros o musmo con codo o rodilla a 90 grados * repeticiones: "+tera2; 
        c=" 3.Reeducacion postular, mover hombros hacia atras * repeticiones: "+tera3;
        d=" 4.Halar una liga con el antebrazo o pierna (bilateralmente) * repeticiones: "+tera4;
        e=" 5.Precion hacia el centro en codo o rodilla * repeticiones: "+tera5;
        cout<<z<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
        terapia=" ";
        do
        {
            cout<<"Escoja que ejercicios va a asignar: "<<endl;
            cin>>rta;
            if(rta==1)
            {
                cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                z=" 1.Equilibrio en una pierna mientras toca el piso * repeticiones: "+tera1;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==2)
			{
                cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera2; cout<<endl;
                b=" 2.Rotacion interna de hombros o musmo con codo o rodilla a 90 grados * repeticiones: "+tera2;
				terapia=terapia+" "+end+b;
			}
			else if(rta==3)
			{
                cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera3; cout<<endl;
                c=" 3.Reeducacion postular, mover hombros hacia atrás * repeticiones: "+tera3;
				terapia=terapia+" "+end+c;
			}
			else if(rta==4)
			{
                cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera4; cout<<endl;
                d=" 4.Halar una liga con el antebrazo o pierna (bilateralmente) * repeticiones: "+tera4;
				terapia=terapia+" "+end+d;
			}
			else if(rta==5)
			{
                cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera5; cout<<endl;
                e=" 5.Precion hacia el centro en hombro o rodilla * repeticiones: "+tera5;
				terapia=terapia+" "+end+e;
			}
            cout<<endl<<endl<<"Quiere asignar mas terapias?(s/n)"<<endl;
            cin>>respuesta;
        }
        while(respuesta=='s'); //Do while para sumar las asignaciones
        a[id_unico]=a[id_unico]+" Terapias: "+terapia+end; //Acumula las asignaciones en el historial cl?nica 
        cout<<"Los ejercicios a realizar para la siguiente consulta son"<<"\n"<<a[id_unico]<<endl;
        break;
    case 2:
        z=" 1.Ejercicio de plancha * minutos: "+tera1;
        b=" 2.Ejercicio de extension de rodilla (Pasivo y activo) * repeticiones: "+tera2;
        c=" 3.Ejercicio de sentadillas * repeticiones: "+tera3;
        d=" 4.Ejercicio para fascitis plantar * repeticiones: "+tera4;
        e=" 5.Ejercicio de estiramiento de columna * minutos: "+tera5;
        cout<<z<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
        terapia=" ";
        do
        {

            cout<<"Escoja que ejercicios va a asignar: "<<endl;
            cin>>rta;
            if(rta==1)
            {
            	cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                z=" 1.Ejercicio de plancha * minutos: "+tera1;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==2)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                b=" 2.Ejercicio de extension de rodilla (Pasivo y activo) * repeticiones: "+tera2;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==3)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                c=" 3.Ejercicio de sentadillas * repeticiones: "+tera3;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==4)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                d=" 4.Ejercicio para fascitis plantar * repeticiones: "+tera4;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==5)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                e=" 5.Ejercicio de estiramiento de columna * minutos: "+tera5;
            	terapia=terapia+" "+end+z;
			}
            cout<<endl<<endl<<"Quiere asignar mas terapias?(s/n)"<<endl;
            cin>>respuesta;
        }
        while(respuesta=='s');//Do while para sumar las asignaciones
        a[id_unico]=a[id_unico]+terapia+end;//Acumula las asignaciones en el historial cl?nica 
        cout<<"Los ejercicios a realizar para la siguiente consulta son"<<"\n"<<a[id_unico]<<endl;
        break;
    case 3:
        z=" 1.CrioTerapia (Frio y Calor) *minutos:"+tera1;
        b=" 2.Vendaje Funcional * cantidad de dias:"+tera2;
        c=" 3.Masajes en el musculo afectado repeticiones por semana * "+tera3;
        d=" 4.Kinesiterapia en musculo lesionado* cantidad de dias"+tera4;
        e=" 5.Estiramiento articular * repeticiones "+tera5;
        cout<<z<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
        terapia=" ";
        do
        {
            cout<<"Escoja que ejercicios va a asignar: "<<endl;
            cin>>rta;
            if(rta==1)
            {
            	cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                z=" 1.CrioTerapia (Frio y Calor) *minutos:"+tera1;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==2)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                b=" 2.Vendaje Funcional * cantidad de dias:"+tera2;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==3)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                c=" 3.Masajes en el musculo afectado repeticiones por semana * "+tera3;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==4)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                d=" 4.Kinesiterapia en musculo lesionado* cantidad de dias: "+tera4;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==5)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                e=" 5.Estiramiento articular * repeticiones: "+tera5;
            	terapia=terapia+" "+end+z;
			}
            cout<<endl<<endl<<"Quiere asignar mas terapias?(s/n)"<<endl;
            cin>>respuesta;
        }
        while(respuesta=='s');
        a[id_unico]=a[id_unico]+terapia+end;
        cout<<"Los ejercicios a realizar para la siguiente consulta son"<<"\n"<<a[id_unico]<<endl;
        break;
    case 4:
        z=" 1.Aerobicos * minutos: "+tera1;
        b=" 2.Levantamiento de mancuernas de poco peso * repeticiones: "+tera2; 
        c=" 3.Bandas elasticas * repeticiones: "+tera3; 
        d=" 4.Pedales estaticos * minutos: "+tera4; 
        e=" 5.Estiramiento de articulaciones * repeticiones: "+tera5;
        cout<<z<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
        terapia=" ";
        do
        {
            cout<<"Escoja que ejercicios va a asignar: "<<endl;
            cin>>rta;
            if(rta==1)
            {
            	cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                z=" 1. 1.Aerobicos * minutos: "+tera1;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==2)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                b=" 2.Levantamiento de mancuernas de poco peso * repeticiones: "+tera2;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==3)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                c=" 3.Bandas elasticas * repeticiones: "+tera3;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==4)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                d=" 4.Pedales estaticos * minutos: "+tera4;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==5)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                e=" 5.Estiramiento de articulaciones * repeticiones: "+tera5;
            	terapia=terapia+" "+end+z;
			}
            cout<<endl<<endl<<"Quiere asignar mas terapias?(s/n)"<<endl;
            cin>>respuesta;
        }
        while(respuesta=='s');
        a[id_unico]=a[id_unico]+terapia+end;
        cout<<"Los ejercicios a realizar para la siguiente consulta son"<<"\n"<<a[id_unico]<<endl;
        break;
    case 5:
        z=" 1.Buscar parejas de cartas * repeticiones: "+tera1;
        b=" 2.Sopa de letras * cantidad : "+tera2; 
        c=" 3.Ejercicios de memoria * minutos: "+tera3; 
        d=" 4.Desarrollar rompe-cabezas * repeticiones: "+tera4;
        e=" 5.Planas en una hoja * repeticiones: "+tera5;
        cout<<z<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
        terapia=" ";
        do
        {
            cout<<"Escoja que ejercicios va a asignar: "<<endl;
            cin>>rta;
            if(rta==1)
            {
            	cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                z=" 1.Ejercicio Neurologico * repeticiones: "+tera1;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==2)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                b=" 2.Ejercicio Neurologico * repeticiones: "+tera2;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==3)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                c=" 3.Ejercicio Neurologico * repeticiones: "+tera3;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==4)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                d=" 4.Ejercicio Neurologico * repeticiones: "+tera4;
            	terapia=terapia+" "+end+z;
			}
			else if(rta==5)
			{
				cout<<"Digite la cantidad de repeticiones: "<<endl;
                cin>>tera1; cout<<endl;
                e=" 5.Ejercicio Neurologico * repeticiones: "+tera5;
            	terapia=terapia+" "+end+z;
			}
            cout<<endl<<endl<<"Quiere asignar mas terapias?(s/n)"<<endl;
            cin>>respuesta;
        }
        while(respuesta=='s');
        a[id_unico]=a[id_unico]+terapia+end;
        cout<<"Los ejercicios a realizar para la siguiente consulta son"<<"\n"<<a[id_unico]<<endl;
        break;
    default:
        break;
    }
    
}