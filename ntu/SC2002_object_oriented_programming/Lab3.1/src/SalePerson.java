public class SalePerson implements Comparable {
    private  String firstName, lastName;
    private  int totalSales;
    //-----------------------------------------------------------------
    public SalePerson (String first, String last,int sales)
    {
        firstName = first;
        lastName = last;
        totalSales = sales;
    }
    public String toString() {
        return this.firstName+","+ this.lastName+":"+ this.totalSales;
    }
    public boolean equals(Object other) {
        if (other instanceof SalePerson) {
            SalePerson otherSalePerson = (SalePerson) other;
            return this.firstName.equals(otherSalePerson.firstName) && this.lastName.equals(otherSalePerson.lastName);
        }
        return false;
    }
    public int compareTo(Object other) {
        if (other instanceof SalePerson) {
            SalePerson otherSalePerson = (SalePerson) other;
            if (this.totalSales > otherSalePerson.totalSales) {
                return 1;
            } else if (this.totalSales < otherSalePerson.totalSales) {
                return -1;
            } else {
                if(this.lastName.compareTo(otherSalePerson.lastName) > 0) {
                    return -1;
                } else if(this.lastName.compareTo(otherSalePerson.lastName) < 0) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
        return -1;
    }
    //-----------------------------------------------------------------
    public String getFirstName()
    {
        return firstName;
    }
    public String getLastName()
    {
        return lastName;
    }
    public int getTotalSales()
    {
        return totalSales;
    }
}
