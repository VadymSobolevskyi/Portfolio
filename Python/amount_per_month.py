'''
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amount_per_month.py                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vadym Sobolevskyi                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:34:58 by vs                 #+#    #+#            */
/*   Updated: 2026/09/24 15:35:03 by vs                 ###   ##########      */
/*                                                                            */
/* ************************************************************************** */
'''
#date start: 05.10
from datetime import date
today = date.today()
print("today:", today)

from datetime import datetime
from dateutil.relativedelta import relativedelta
firstDay="2026-10-05"
print("1st day:", firstDay)

# Current date
firstDay = date(2026, 10, 5) # Example date: January 23, 2026

# Add one month
lastDay = firstDay + relativedelta(months=1)

print("New Date:", lastDay) # Output: New Date: 2026-02-23 00:00:00

delta=lastDay-today

print(f"Number of days left: {delta.days}")

delta2=today-firstDay
print(f"Number of days passed: {delta2.days}")
totalDays=lastDay-firstDay

sum=338
checks=(60.69, 3.49, 30.39, 32.25, 9.30, 5.16)
checksTotal=0
rest=sum
for i in checks:
checksTotal+=i
rest=sum-checksTotal
print("checksTotal: %.2f" % checksTotal)
print("rest: %.2f" % rest)
percentUsed=100*checksTotal/sum
print("percent used: %.0f" % percentUsed)
print("percent days passed: %.0f" % (100*delta2/totalDays))

print("normal day: %.2f" % (sum/30))
print("normal week: %.2f" % (7*sum/30))

print("current day: %.2f" % (rest/delta.days))
print("current week: %.2f" % (7*rest/delta.days))
#
print("[", end="")
for j in range (1, totalDays.days, 1):
if (j%7==0):
print("|", end="")
else:
print(".", end="")
print("]")

print("[", end="")
for j in range (1, totalDays.days, 1):
if (j%7==0):
print("|", end="")
else:
if (j<=delta2.days):
print("|", end="")
else:
print(".", end="")
print("] - days passed")

print("[", end="")
for j in range (1, totalDays.days, 1):
if (j%7==0):
print("|", end="")
else:
if (100*j/totalDays.days<percentUsed):
print("|", end="")
else:
print(".", end="")
print("] - used by day", end="")
print(" (%.0f%%)" % percentUsed)
print("used: %.2f" % checksTotal)
print("left: %.2f" % rest)

