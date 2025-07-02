import { CSSProperties, Fragment } from "react";

const sunStyle: CSSProperties = {
    width: 40,
    height: 40,
    background: "radial-gradient(circle at 30% 30%, #FFD700, #FFA500 80%)",
    borderRadius: "50%",
    position: "absolute",
    left: "50%",
    top: "50%",
    transform: "translate(-50%, -50%)",
    boxShadow: "0 0 30px 10px #FFD70088",
    zIndex: 2,
};

const orbitStyle = (radius: number) =>
    ({
        position: "absolute",
        left: "50%",
        top: "50%",
        width: radius * 2,
        height: radius * 2,
        marginLeft: -radius,
        marginTop: -radius,
        border: "1px dashed #aaa3",
        borderRadius: "50%",
        zIndex: 1,
    } as React.CSSProperties);

const planetStyle = (
    size: number,
    color: string,
    orbitRadius: number,
    duration: number,
    delay: number
) =>
    ({
        width: size,
        height: size,
        background: color,
        borderRadius: "50%",
        position: "absolute",
        left: "50%",
        top: "50%",
        transform: `translate(-50%, -50%)`,
        animation: `orbit-${orbitRadius} ${duration}s linear infinite`,
        animationDelay: `${delay}s`,
        boxShadow: `0 0 8px 2px ${color}88`,
        zIndex: 3,
    } as React.CSSProperties);

const planets = [
    { size: 10, color: "#6cf", radius: 30, duration: 1.5, delay: 0 },
    { size: 14, color: "#9f6", radius: 50, duration: 2.2, delay: 0.3 },
    { size: 12, color: "#f96", radius: 70, duration: 3, delay: 0.7 },
];

const overlayStyle: CSSProperties = {
    position: "fixed",
    top: 0,
    left: 0,
    width: "100vw",
    height: "100vh",
    background: "rgba(0,0,0,0.3)",
    zIndex: 9999,
    display: "flex",
    alignItems: "center",
    justifyContent: "center",
};

const loaderBoxStyle: CSSProperties = {
    position: "relative",
    width: 160,
    height: 160,
    display: "flex",
    alignItems: "center",
    justifyContent: "center",
};

const Loader: React.FC = () => (
    <div style={overlayStyle}>
        <div style={loaderBoxStyle}>
            <div style={sunStyle} />
            {planets.map((p, i) => (
                <Fragment key={i}>
                    <div style={orbitStyle(p.radius)} />
                    <div
                        style={{
                            ...planetStyle(p.size, p.color, p.radius, p.duration, p.delay),
                            animationName: `orbit-${p.radius}`,
                        }}
                    />
                </Fragment>
            ))}
            <style>
                {planets
                    .map(
                        (p) => `
                            @keyframes orbit-${p.radius} {
                                0% { transform: rotate(0deg) translate(${p.radius}px) rotate(0deg); }
                                100% { transform: rotate(360deg) translate(${p.radius}px) rotate(-360deg); }
                            }
                        `
                    )
                    .join("\n")}
            </style>
        </div>
    </div>
);

export default Loader;
