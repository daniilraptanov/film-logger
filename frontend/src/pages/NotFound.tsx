import SpaceBackground from "../shared/SpaceBackground";

const NotFound = () => (
    <SpaceBackground>
        <svg
            width="80"
            height="80"
            viewBox="0 0 64 64"
            fill="none"
            style={{ zIndex: 1, marginBottom: 24 }}
        >
            <rect x="8" y="20" width="48" height="32" rx="6" fill="#222" stroke="#fff" strokeWidth="2" />
            <circle cx="32" cy="36" r="10" fill="#111" stroke="#fff" strokeWidth="2" />
            <rect x="24" y="14" width="16" height="8" rx="2" fill="#333" stroke="#fff" strokeWidth="2" />
            <circle cx="32" cy="36" r="4" fill="#fff" opacity="0.3" />
        </svg>
        <h1 style={{ fontSize: "3rem", fontWeight: 700, letterSpacing: "0.1em", zIndex: 1 }}>
            404
        </h1>
        <p style={{ fontSize: "1.5rem", margin: "16px 0 0 0", zIndex: 1 }}>
            Lost in Space & Light
        </p>
        <p style={{ fontSize: "1rem", margin: "8px 0 0 0", color: "#bbb", zIndex: 1 }}>
            Сторінка, яку ви шукаєте, відсутня.
            Можливо, спробувати зняти ще один кадр?
        </p>
    </SpaceBackground>
);

export default NotFound;
