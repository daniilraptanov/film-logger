import { FC, ReactNode } from "react";

interface SpaceBackgroundProps {
    children: ReactNode;
}

const SpaceBackground: FC<SpaceBackgroundProps> = (props) => {
    return (
        <div
            style={{
                minHeight: "100vh",
                background: "radial-gradient(ellipse at center, #232526 0%, #0f2027 100%)",
                color: "#fff",
                display: "flex",
                flexDirection: "column",
                alignItems: "center",
                justifyContent: "center",
                fontFamily: "'Montserrat', 'Helvetica Neue', Arial, sans-serif",
                position: "relative",
                overflow: "hidden",
            }}
        >
            {/* Stars */}
            <div
                style={{
                    position: "absolute",
                    width: "100%",
                    height: "100%",
                    top: 0,
                    left: 0,
                    pointerEvents: "none",
                    zIndex: 0,
                }}
            >
                {[...Array(80)].map((_, i) => (
                    <div
                        key={i}
                        style={{
                            position: "absolute",
                            top: `${Math.random() * 100}%`,
                            left: `${Math.random() * 100}%`,
                            width: `${Math.random() * 2 + 1}px`,
                            height: `${Math.random() * 2 + 1}px`,
                            background: "#fff",
                            borderRadius: "50%",
                            opacity: Math.random() * 0.8 + 0.2,
                            filter: "blur(0.5px)",
                        }}
                    />
                ))}
            </div>
            {props.children}
        </div>
    );
}

export default SpaceBackground;
