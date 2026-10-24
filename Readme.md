# Electricity Consumption and Billing System

An electricity provider program designed to calculate household electricity bills based on consumption and customer categories. 

## System Overview

The system can store information for a maximum of **20 households**. Stored data includes:
- Customer Name
- Customer Category
- Daily electricity usage (for 7 days)
- Total electricity usage
- Final electricity bill

## Minimum Requirements

- **Household Registration:** Register households and record daily electricity consumption for 7 days.
- **Consumption Analytics:** Calculate the total electricity consumption, average daily consumption, and estimated monthly consumption based on the recorded 7-day usage.
- **Peak Usage Identification:** Identify the specific day with the highest electricity consumption for each household.
- **Reporting System:** Generate and display a comprehensive report containing customer information, total electricity consumption, estimated monthly consumption, applied discount, and final electricity bill.

### Progressive Tariffs

Electricity bills are calculated using a progressive tariff system:

| Consumption Range | Rate per kWh |
| :--- | :--- |
| First 100 kWh | Rp1,000 |
| Next 100 kWh | Rp1,500 |
| Above 200 kWh | Rp2,000 |

### Customer Category Discounts

Final bills are adjusted with discounts based on the customer's income category:

| Customer Category | Discount Applied |
| :--- | :--- |
| Low-income | 20% |
| Middle-income | 10% |
| High-income | 0% (No discount) |
