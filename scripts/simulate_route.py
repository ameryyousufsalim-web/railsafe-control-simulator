class TrackSection:
    def __init__(self, section_id):
        self.section_id = section_id
        self.occupied = False


class Signal:
    def __init__(self):
        self.state = "RED"

    def set_green(self):
        self.state = "GREEN"

    def set_red(self):
        self.state = "RED"


class Train:
    def __init__(self, train_id):
        self.train_id = train_id
        self.current_section = None


def can_enter(signal, section):
    return signal.state == "GREEN" and not section.occupied


def simulate_route():
    sections = [TrackSection(i) for i in range(1, 5)]
    signals = [Signal() for _ in sections]
    train = Train("RB-42")

    print("RailSafe Python Route Simulation")
    print("--------------------------------")

    for index, section in enumerate(sections):
        signal = signals[index]
        signal.set_green()

        print(f"Checking section {section.section_id} with signal {signal.state}...")

        if can_enter(signal, section):
            if train.current_section is not None:
                train.current_section.occupied = False

            section.occupied = True
            train.current_section = section

            print(f"Train {train.train_id} entered section {section.section_id} safely.")
        else:
            print(f"Movement blocked for train {train.train_id}.")
            break

    print("--------------------------------")
    print(f"Simulation finished. Train is now in section {train.current_section.section_id}.")


if __name__ == "__main__":
    simulate_route()