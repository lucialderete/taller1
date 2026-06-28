
//2c

Empleado[] empleados= new Empleado[3]; //crea el espacio para guardar los datos de los 3 empleadps

empleados[0] = new Empleado(
    "Juan", "Perez", new DateTime(1993, 8, 18), 'C', new DateTime(2021,3, 1), 200000, Cargos.Ingeniero
);

empleados[1] = new Empleado(
    "Maria", "Pepita", new DateTime(2002, 6, 3), 'S', new DateTime(2025,12, 12), 180000, Cargos.Administrativo
);

empleados[2] = new Empleado(
    "Pedro", "Gomez", new DateTime(1973, 4, 14), 'C', new DateTime(2000,5, 7), 900000, Cargos.Investigador
);


//2d
double TotalSalarios=0;
for(int i=0; i<empleados.Length; i++)
{
    TotalSalarios += empleados[i].Salario;
}
Console.WriteLine($"El monto total de lo que se paga en concepto Salarios es {TotalSalarios}");

int indice=0;
for(int i=0; i<empleados.Length; i++)
{
    if (empleados[i].AniosParaJubilarse < empleados[indice].AniosParaJubilarse)
    {
        indice = i;
    }
}
Console.WriteLine("El empleado proximo a Jubilarese es: ");
Console.WriteLine($"Nombre y Apellido: {empleados[indice].Nombre} {empleados[indice].Apellido}");
Console.WriteLine($"Fecha de Nacimiento: {empleados[indice].FechaNac.ToShortDateString()}");
Console.WriteLine($"Edad: {empleados[indice].Edad}");

Console.WriteLine($"Estado Civil: {empleados[indice].EstadoCivil}");
Console.WriteLine($"Fecha Ingreso a la empresa: {empleados[indice].FechaIngreso.ToShortDateString()}");
Console.WriteLine($"Antiguedad: {empleados[indice].Antiguedad}");
Console.WriteLine($"Sueldo basico: {empleados[indice].SueldoBasico}");
Console.WriteLine($"Cargo: {empleados[indice].Cargo}");
Console.WriteLine($"Cantidad de Años que le faltan para Jubilarse: {empleados[indice].AniosParaJubilarse}");
Console.WriteLine($"Salario total: {empleados[indice].Salario}");






