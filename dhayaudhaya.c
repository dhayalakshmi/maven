interface Employee
{
    double earnings(double basicSalary);
    double deductions(double basicSalary);
    double bonus(double basicSalary);
}
abstract class Manager implements Employee
{
    public double earnings(double basicSalary)
    {
       return basicSalary+(0.8*basicSalary)+(0.15*basicSalary);
    }
    public double deductions(double basicSalary)
    {
        return 0.12*basicSalary;
    }
}
class Substaff extends Manager
{
    public double bonus(double basicSalary)
    {
        return 0.5*basicSalary;
    }
}
