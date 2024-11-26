import java.util.ArrayList;
import java.util.List;

public class Inter {
    
    public interface Playable {
        void play();
    }

    public interface Tunable {
        void tune();
    }

    public static class Orchestra {
        private List<Playable> instruments;

        public Orchestra() {
            instruments = new ArrayList<>();
        }

        public void addInstrument(Playable instrument) {
            instruments.add(instrument);
        }
        
        public void playAll() {
            System.out.println("Orchestra is playing: ");
            for (Playable instrument: instruments) {
                instrument.play();
            }
        }
    }

    public static class Guitar implements Playable,Tunable {
        @Override
        public void play() {
            System.out.println("Playing the guitar - strum, strum.");
        }
        
        @Override
        public void tune() {
            System.out.println("Tuning the guitar.");
        }
    }

    public static class Piano implements Playable,Tunable {
        @Override
        public void play() {
            System.out.println("Playing the piano - plink, plonk.");
        }
        @Override
        public void tune() {
            System.out.println("Tuning the piano.");
        }
    }

    public static class Drum implements Playable {
        @Override
        public void play() {
            System.out.println("Playing the drums - bang, boom.");
        }
    }

    public static class Violin implements Playable {
        public void play() {
            System.out.println("Playing the violin - goida.");
        }
    }

    public static class Flute implements Playable {
        public void play() {
            System.out.println("Playing the flute - goool");
        }
    }
    public static void main(String[] args) {
        Orchestra orchestra = new Orchestra();
        
        Guitar guitar = new Guitar();
        Piano piano = new Piano();
        Drum drum = new Drum();
        Violin violin = new Violin();
        Flute flute = new Flute();

        orchestra.addInstrument(guitar);
        orchestra.addInstrument(piano);
        orchestra.addInstrument(drum);
        orchestra.addInstrument(violin);
        orchestra.addInstrument(flute);

        orchestra.playAll();
    }
}