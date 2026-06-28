using System.Data.Common;

Console.WriteLine("---CALCULADORA---");
int opcion;
do
{
    Console.WriteLine("Seleccione una opcion");
    Console.WriteLine("1) SUMAR");
    Console.WriteLine("2) RESTAR");
    Console.WriteLine("3) MULTIPLICAR");
    Console.WriteLine("4) DIVIDIR");
    
    Console.WriteLine("5) VALOR ABSOLUTO");
    Console.WriteLine("6) EL CUADRADO");
    Console.WriteLine("7) RAIZ CUADRADA");
    Console.WriteLine("8) SENO");
    Console.WriteLine("9) COSENO");
    Console.WriteLine("10) PARTE ENETERA DE UN FLOAT");

    Console.WriteLine("0) SALIR");

    string opcionTexto = Console.ReadLine();
    if(int.TryParse(opcionTexto, out opcion))
    {
        double resultado =0;
        double n1, n2;
        if (opcion == 0)
        {
            break;
        }else if(opcion >= 1 && opcion <= 4)
        {
            Console.WriteLine("Ingrese el primer numero");
            string numero1 = Console.ReadLine();
            Console.WriteLine("Ingrese el segundo numero");
            string numero2 = Console.ReadLine();

            if(double.TryParse(numero1, out n1) && double.TryParse(numero2, out n2))
            {
                switch (opcion)
                {
                    case 1: resultado = n1 + n2;
                    break;
                    case 2: resultado = n1 - n2;
                    break;
                    case 3: resultado = n1 * n2;
                    break;
                    case 4:
                        if (n2 != 0)
                        {
                            resultado = n1 / n2;
                        }
                        else
                        {
                            Console.WriteLine("ERROR. no se puede dividir en 0");
                            continue;
                        }
                        break;
                }

            }
            else
            {
                Console.WriteLine("Ingrese numeros validos");
            }
        }
        else if(opcion >= 5 && opcion <= 10)
        {
            Console.WriteLine("Ingrese un numero");
            string numero1 = Console.ReadLine();
            if(double.TryParse(numero1, out n1))
            {
                switch (opcion)
                {
                    case 5: resultado = Math.Abs(n1);
                    break;
                    case 6: resultado = n1*n1;
                    break;
                    case 7: resultado = Math.Sqrt(n1);
                    break;
                    case 8: resultado = Math.Sin(n1);
                    break;
                    case 9: resultado = Math.Cos(n1);
                    break;
                    case 10: resultado = Math.Truncate(n1);
                    break;
                }

            }
            else
            {
                Console.WriteLine("Ingrese un numero valido");
            }
        }
        Console.WriteLine($"El resultado es: {resultado}");

    }
    else
    {
        Console.WriteLine("ingrese un numero");
    }
    
}while(opcion!=0);