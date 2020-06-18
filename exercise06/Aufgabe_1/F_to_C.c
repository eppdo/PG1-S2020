// Funktion Umrechnung: Fahrenheit -> Celsius
float FtoC(float FahrenheitValue)
{
	float CelsiusValue;

	CelsiusValue = (FahrenheitValue - 32) / 1.8;

	return CelsiusValue;
}