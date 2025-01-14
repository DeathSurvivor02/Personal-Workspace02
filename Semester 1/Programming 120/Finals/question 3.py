def cars_that_can_fit(parking_lot):
    cars_fit_per_row = []
    for row in parking_lot:
        empty_spots = row.count(' ')
        cars_fit_per_row.append(empty_spots)
    return cars_fit_per_row