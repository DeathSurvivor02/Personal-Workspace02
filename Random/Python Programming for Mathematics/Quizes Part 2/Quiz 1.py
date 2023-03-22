def total_seconds(hours, minutes, seconds):
	total_seconds = 0
	if hours > 0:
		total_seconds += hours * 60 * 60
	if minutes > 0:
		total_seconds += minutes * 60
	if seconds > 0:
		total_seconds += seconds
	return(total_seconds)

	