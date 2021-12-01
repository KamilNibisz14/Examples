// Program który mnoży liczby rzeczywiste po przez dodawanie.

package com.example.project;

public class Project {
    public static void main(String[] args) {
        double d1 = 3.14;
        double d2 = 4.18;
        boolean minus = (d1 < 0 ^ d2 < 0);
        String s1 = Double.toString(d1 < 0 ? -d1 : d1);
        String s2 = Double.toString(d2 < 0 ? -d2 : d2);
        int dot1 = s1.indexOf('.');
        int dot2 = s2.indexOf('.');

        s1 = s1.replace(".", "");
        s2 = s2.replace(".", "");

        long l1 = Long.parseLong(s1);
        long l2 = Long.parseLong(s2);
        long w = 0;
        long t = l1;
        for(int o = 1; o <= l2; o+=o, t+=t) {
            if ((l2 & o) > 0) {
                w += t;
            }
        }
        String s = Long.toString(w);
        int lvlD = s.length() - (s1.length() + s2.length() - (dot1 + dot2));
        String str = s.substring(0, lvlD) + '.' + s.substring(lvlD);
        Double result =  Double.parseDouble(str);
        if (minus) {
            result = -result;
        }
        System.out.println(result);
    }
}
